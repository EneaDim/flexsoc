#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
HJSON/JSON Config Editor (GUI moderna)
- Carica/salva .hjson/.json (preferenza HJSON se installato; fallback a JSON se HJSON fallisce)
- Navigazione ad albero con editor a destra
- Rinomina chiavi (dict), editing scalari tipizzati (string/int/float/bool/null)
- Aggiungi/Elimina figli, riordino elementi di lista (Move Up/Down)
- Scorciatoie: Ctrl+O, Ctrl+S, Ctrl+Shift+S, Del, Insert, F2, Ctrl+↑/↓
- UI moderna: ttkbootstrap (se presente) oppure stile ttk curato
"""

import json
import os
import sys
import tkinter as tk
from tkinter import ttk, filedialog, messagebox
from tkinter.scrolledtext import ScrolledText
import copy
import tempfile
import uuid

# --- Optional deps ---
HJSON_AVAILABLE = True
try:
    import hjson  # pip install hjson
except Exception:
    HJSON_AVAILABLE = False

HAS_BOOTSTRAP = True
try:
    import ttkbootstrap as tb  # pip install ttkbootstrap
except Exception:
    HAS_BOOTSTRAP = False

APP_TITLE = "HJSON Config Editor"
SUPPORTED_OPEN = [("HJSON / JSON", "*.hjson *.json"), ("All files", "*.*")]
DEFAULT_SAVE_EXT = ".hjson" if HJSON_AVAILABLE else ".json"


# -------- helpers (data) --------
def _deep_get(container, path):
    ref = container
    for step in path:
        ref = ref[step]
    return ref

def _deep_set(container, path, value):
    if not path:
        return value
    *parents, last = path
    ref = container
    for step in parents:
        ref = ref[step]
    ref[last] = value
    return container

def _deep_del(container, path):
    *parents, last = path
    ref = container
    for step in parents:
        ref = ref[step]
    if isinstance(ref, list):
        ref.pop(last)
    else:
        del ref[last]

def _move_in_list(container, path, index, delta):
    lst = _deep_get(container, path)
    new_index = index + delta
    if 0 <= new_index < len(lst):
        lst[index], lst[new_index] = lst[new_index], lst[index]
        return new_index
    return index

def _parse_typed_value(text, type_name):
    if type_name == "string":
        return text
    if type_name == "int":
        return int(text, 0)  # accetta 0x.. 0b.. ecc.
    if type_name == "float":
        return float(text)
    if type_name == "bool":
        t = text.strip().lower()
        if t in ("1", "true", "yes", "y", "on"): return True
        if t in ("0", "false", "no", "n", "off"): return False
        raise ValueError("Boolean non valido")
    if type_name == "null":
        return None
    raise ValueError(f"Tipo non supportato: {type_name}")

def _infer_type_name(value):
    if value is None: return "null"
    if isinstance(value, bool): return "bool"
    if isinstance(value, int): return "int"
    if isinstance(value, float): return "float"
    if isinstance(value, str): return "string"
    if isinstance(value, list): return "list"
    if isinstance(value, dict): return "dict"
    return type(value).__name__


# -------- App --------
class App((tb.Window if HAS_BOOTSTRAP else tk.Tk)):
    def __init__(self):
        if HAS_BOOTSTRAP:
            super().__init__(themename="darkly")
        else:
            super().__init__()
            self._apply_ttk_style()
        
        self.original_data = None      # snapshot immutato del file caricato
        self._editing_path = None      # path (lista) del nodo attualmente in editor
        self._temp_path = None         # file temporaneo dove autosalvare la working copy
        self._suppress_autoapply = False  # per evitare ricorsioni durante populate
        self._just_created = set()  # contiene path-tuple dei nodi appena creati/convertiti         

        self.title(APP_TITLE)
        self.geometry("1200x720")
        self.minsize(1600, 600)

        self.file_path = None
        self.data = {}
        self.unsaved = False

        self._build_menu()
        self._build_layout()
        self._bind_shortcuts()
        self._set_status("Pronto")

        self.load_data({})

    # ----- ttk fallback styling -----
    def _apply_ttk_style(self):
        style = ttk.Style()
        try:
            style.theme_use("clam")
        except Exception:
            pass
        style.configure("Treeview", rowheight=26, font=("Segoe UI", 10))
        style.configure("Treeview.Heading", font=("Segoe UI Semibold", 10))
        style.map("Treeview", background=[("selected", "#347deb")], foreground=[("selected", "white")])
        style.configure("TButton", padding=8)
        style.configure("TLabelframe", padding=10)
        style.configure("TLabelframe.Label", font=("Segoe UI Semibold", 10))

    # ----- UI -----
    def _build_menu(self):
        menubar = tk.Menu(self)
        filem = tk.Menu(menubar, tearoff=0)
        filem.add_command(label="Open…", accelerator="Ctrl+O", command=self.on_open)
        filem.add_separator()
        filem.add_command(label="Save", accelerator="Ctrl+S", command=self.on_save)
        filem.add_command(label="Save As…", accelerator="Ctrl+Shift+S", command=self.on_save_as)
        filem.add_separator()
        filem.add_command(label="Exit", command=self.on_quit)
        menubar.add_cascade(label="File", menu=filem)

        editm = tk.Menu(menubar, tearoff=0)
        editm.add_command(label="Add Child (Insert)", command=self.on_add_child)
        editm.add_command(label="Delete Node (Del)", command=self.on_delete)
        editm.add_separator()
        editm.add_command(label="Rename (F2)", command=self.on_rename)
        editm.add_separator()
        editm.add_command(label="Move Up (Ctrl+↑)", command=lambda: self.on_move(-1))
        editm.add_command(label="Move Down (Ctrl+↓)", command=lambda: self.on_move(+1))
        menubar.add_cascade(label="Edit", menu=editm)

        viewm = tk.Menu(menubar, tearoff=0)
        if HAS_BOOTSTRAP:
            viewm.add_command(label="Toggle Light/Dark", command=self._toggle_theme)
        menubar.add_cascade(label="View", menu=viewm)

        helpm = tk.Menu(menubar, tearoff=0)
        helpm.add_command(
            label="About",
            command=lambda: messagebox.showinfo(
                "About",
                f"{APP_TITLE}\n- HJSON: {'Yes' if HJSON_AVAILABLE else 'No'}\n- UI: {'ttkbootstrap' if HAS_BOOTSTRAP else 'ttk'}"
            ),
        )
        menubar.add_cascade(label="Help", menu=helpm)
        self.config(menu=menubar)

    def _toggle_theme(self):
        # Solo ttkbootstrap
        try:
            current = self.style.theme.name  # type: ignore[attr-defined]
            newt = "flatly" if "dark" in current else "darkly"
            self.style.theme_use(newt)      # type: ignore[attr-defined]
        except Exception:
            pass

    def _build_layout(self):
        container = ttk.Frame(self, padding=8)
        container.pack(fill=tk.BOTH, expand=True)

        left = ttk.Frame(container)
        left.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        right = ttk.Frame(container)
        right.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True, padx=(8, 0))

        # Tree
        self.tree = ttk.Treeview(left, columns=("type", "value"), show="tree headings", selectmode="browse")
        self.tree.heading("#0", text="Key / Index")
        self.tree.heading("type", text="Type")
        self.tree.heading("value", text="Value (preview)")
        self.tree.column("#0", width=360, stretch=True)
        self.tree.column("type", width=110, anchor=tk.CENTER)
        self.tree.column("value", width=420, stretch=True)

        vsb = ttk.Scrollbar(left, orient="vertical", command=self.tree.yview)
        hsb = ttk.Scrollbar(left, orient="horizontal", command=self.tree.xview)
        self.tree.configure(yscroll=vsb.set, xscroll=hsb.set)
        self.tree.grid(row=0, column=0, sticky="nsew")
        vsb.grid(row=0, column=1, sticky="ns")
        hsb.grid(row=1, column=0, sticky="we")
        left.rowconfigure(0, weight=1)
        left.columnconfigure(0, weight=1)

        # Context menu
        self.ctx_menu = tk.Menu(self, tearoff=0)
        self.ctx_menu.add_command(label="Apply Changes", command=self.on_apply)
        self.ctx_menu.add_separator()
        self.ctx_menu.add_command(label="Add Child", command=self.on_add_child)
        self.ctx_menu.add_command(label="Delete", command=self.on_delete)
        self.ctx_menu.add_separator()
        self.ctx_menu.add_command(label="Rename (F2)", command=self.on_rename)
        self.ctx_menu.add_separator()
        self.ctx_menu.add_command(label="Move Up", command=lambda: self.on_move(-1))
        self.ctx_menu.add_command(label="Move Down", command=lambda: self.on_move(+1))
        self.tree.bind("<Button-3>", self._tree_context)
        self.tree.bind("<<TreeviewSelect>>", self._on_select)
        self.tree.bind("<Double-1>", self._on_double_click)

        # Editor panel
        editor = ttk.LabelFrame(right, text="Editor", padding=10)
        editor.pack(fill=tk.BOTH, expand=True)

        grid = ttk.Frame(editor)
        grid.pack(fill=tk.X)

        row = 0
        ttk.Label(grid, text="Node Path:").grid(row=row, column=0, sticky=tk.W)
        self.path_var = tk.StringVar()
        ttk.Entry(grid, textvariable=self.path_var, state="readonly").grid(row=row, column=1, columnspan=3, sticky="we", pady=4)
        grid.columnconfigure(1, weight=1); row += 1

        self.key_label = ttk.Label(grid, text="Key / Index:")
        self.key_label.grid(row=row, column=0, sticky=tk.W)
        self.key_var = tk.StringVar()
        self.key_entry = ttk.Entry(grid, textvariable=self.key_var)
        self.key_entry.grid(row=row, column=1, sticky="we", pady=4)

        ttk.Label(grid, text="Type:").grid(row=row, column=2, sticky=tk.W)
        self.type_var = tk.StringVar()
        self.type_combo = ttk.Combobox(
            grid, textvariable=self.type_var, state="readonly",
            values=["string", "int", "float", "bool", "null", "dict", "list"]
        )
        self.type_combo.grid(row=row, column=3, sticky="we")
        row += 1

        ttk.Label(grid, text="Value:").grid(row=row, column=0, sticky=tk.NW)
        self.value_text = ScrolledText(grid, height=12, wrap=tk.WORD)
        self.value_text.grid(row=row, column=1, columnspan=3, sticky="nsew", pady=6)
        grid.rowconfigure(row, weight=1); row += 1

        # Buttons
        btns = ttk.Frame(editor)
        btns.pack(fill=tk.X, pady=(8, 0))
        self.apply_btn = ttk.Button(btns, text="Apply Changes", command=self.on_apply)
        self.apply_btn.pack(side=tk.LEFT)
        ttk.Button(btns, text="Add Child", command=self.on_add_child).pack(side=tk.LEFT, padx=6)
        ttk.Button(btns, text="Delete", command=self.on_delete).pack(side=tk.LEFT, padx=6)
        ttk.Button(btns, text="Rename (F2)", command=self.on_rename).pack(side=tk.LEFT, padx=6)
        ttk.Button(btns, text="Move Up", command=lambda: self.on_move(-1)).pack(side=tk.LEFT, padx=6)
        ttk.Button(btns, text="Move Down", command=lambda: self.on_move(+1)).pack(side=tk.LEFT, padx=6)

        # Status
        self.status = ttk.Label(self, text="", anchor=tk.W)
        self.status.pack(side=tk.BOTTOM, fill=tk.X, padx=8, pady=4)

    def _bind_shortcuts(self):
        self.bind("<Control-o>", lambda e: self.on_open())
        self.bind("<Control-s>", lambda e: self.on_save())
        self.bind("<Control-S>", lambda e: self.on_save_as())
        self.bind("<Delete>", lambda e: self.on_delete())
        self.bind("<Insert>", lambda e: self.on_add_child())
        self.bind("<F2>", lambda e: self.on_rename())
        self.bind("<Control-Up>", lambda e: self.on_move(-1))
        self.bind("<Control-Down>", lambda e: self.on_move(+1))
        self.protocol("WM_DELETE_WINDOW", self.on_quit)

    def _create_tempfile_hint(self):
        """Prepara un nome leggibile per l’autosalvataggio (non crea file finché non serve)."""
        base = os.path.basename(self.file_path) if self.file_path else "untitled.hjson"
        ext  = ".hjson" if HJSON_AVAILABLE else ".json"
        rand = uuid.uuid4().hex[:6]
        self._temp_path = os.path.join(tempfile.gettempdir(), f"{base}.autosave.{rand}{ext}")
    
    def _autosave_temp(self):
        """Scrive SEMPRE la working copy su un file temporaneo, senza toccare l’originale."""
        if not self._temp_path:
            self._create_tempfile_hint()
        try:
            # usa la stessa logica dello _write_file ma forza il path temp
            if HJSON_AVAILABLE and self._temp_path.lower().endswith(".hjson"):
                try:
                    text = hjson.dumps(self.data, ensure_ascii=False, indent=2, sort_keys=False)
                except TypeError:
                    text = hjson.dumps(self.data)
            else:
                text = json.dumps(self.data, ensure_ascii=False, indent=2)
            with open(self._temp_path, "w", encoding="utf-8") as f:
                f.write(text)
            self._set_status(f"Auto-apply e autosave → {os.path.basename(self._temp_path)}")
        except Exception as e:
            # niente popup, solo status
            self._set_status(f"Autosave temporaneo fallito: {e}")
    
    def _path_key(self, path_list):
        # tuple nested-friendly: ["registers", 0, "fields"] -> ("registers", 0, "fields")
        return tuple(path_list or [])
    

    # ----- File ops -----
    def on_open(self):
        path = filedialog.askopenfilename(title="Open Config", filetypes=SUPPORTED_OPEN)
        if not path:
            return
        try:
            with open(path, "r", encoding="utf-8") as f:
                text = f.read()
            if HJSON_AVAILABLE:
                data = hjson.loads(text)
            else:
                cleaned = "\n".join(line for line in text.splitlines() if not line.strip().startswith("//"))
                data = json.loads(cleaned)
            if not isinstance(data, (dict, list)):
                raise ValueError("Il root deve essere dict o list.")
    
            self.file_path = path
            self.original_data = copy.deepcopy(data)  # snapshot immutabile
            self.load_data(copy.deepcopy(data))       # working copy mostrata in GUI
    
            # prepara/azzera file temporaneo
            self._temp_path = None
            self._create_tempfile_hint()
    
            self._set_status(f"Caricato: {os.path.basename(path)}")
        except Exception as e:
            messagebox.showerror("Errore Apertura", f"Impossibile caricare:\n{e}")

    def on_save(self):
        if not self.file_path:
            return self.on_save_as()
        if not messagebox.askyesno("Conferma", f"Sovrascrivere il file originale?\n{self.file_path}"):
            return
        try:
            self._write_file(self.file_path)
            self.unsaved = False
            self._refresh_title()
            self._set_status(f"Salvato: {os.path.basename(self.file_path)}")
        except Exception as e:
            messagebox.showerror("Errore Salvataggio", f"Impossibile salvare:\n{e}")
    
    def on_save_as(self):
        path = filedialog.asksaveasfilename(
            title="Save Config As",
            defaultextension=DEFAULT_SAVE_EXT,
            filetypes=[("HJSON", "*.hjson"), ("JSON", "*.json"), ("All files", "*.*")]
        )
        if not path:
            return
        try:
            self._write_file(path)
            self.file_path = path
            self.unsaved = False
            self._refresh_title()
            self._set_status(f"Salvato come: {os.path.basename(path)}")
        except Exception as e:
            messagebox.showerror("Errore Salvataggio", f"Impossibile salvare:\n{e}")

    def _write_file(self, path):
        """Salvataggio robusto: HJSON se possibile, altrimenti JSON. Niente opzioni non supportate."""
        if HJSON_AVAILABLE and path.lower().endswith(".hjson"):
            try:
                # Opzioni compatibili con il port Python
                text = hjson.dumps(self.data, ensure_ascii=False, indent=2, sort_keys=False)
            except TypeError:
                # Versioni più vecchie: minimo indispensabile
                text = hjson.dumps(self.data)
            except Exception:
                # Fallback a JSON leggibile
                text = json.dumps(self.data, ensure_ascii=False, indent=2)
        else:
            text = json.dumps(self.data, ensure_ascii=False, indent=2)
        with open(path, "w", encoding="utf-8") as f:
            f.write(text)

    def on_quit(self):
        if self.unsaved and not messagebox.askyesno("Modifiche non salvate", "Uscire senza salvare?"):
            return
        self.destroy()

    # ----- Data <-> Tree -----
    def load_data(self, data):
        self.data = data
        self.tree.delete(*self.tree.get_children())
        if isinstance(data, dict):
            self.tree.insert("", "end", iid="root", text="<root>", values=("dict", ""), open=True)
            self._insert_dict_nodes("root", data)
        elif isinstance(data, list):
            self.tree.insert("", "end", iid="root", text="<root>", values=("list", f"[{len(data)}]"), open=True)
            self._insert_list_nodes("root", data)
        else:
            self.tree.insert("", "end", iid="root", text="<root>", values=(_infer_type_name(data), repr(data)), open=True)
        self.unsaved = False
        self._refresh_title()
        self._clear_editor()

    def _insert_dict_nodes(self, parent, d):
        for k, v in d.items():
            t = _infer_type_name(v)
            if isinstance(v, dict):
                node = self.tree.insert(parent, "end", text=str(k), values=("dict", ""), open=False)
                self._insert_dict_nodes(node, v)
            elif isinstance(v, list):
                node = self.tree.insert(parent, "end", text=str(k), values=("list", f"[{len(v)}]"), open=False)
                self._insert_list_nodes(node, v)
            else:
                self.tree.insert(parent, "end", text=str(k), values=(t, self._preview_value(v)), open=False)

    def _insert_list_nodes(self, parent, lst):
        for idx, v in enumerate(lst):
            t = _infer_type_name(v)
            if isinstance(v, dict):
                node = self.tree.insert(parent, "end", text=f"[{idx}]", values=("dict", ""), open=False)
                self._insert_dict_nodes(node, v)
            elif isinstance(v, list):
                node = self.tree.insert(parent, "end", text=f"[{idx}]", values=("list", f"[{len(v)}]"), open=False)
                self._insert_list_nodes(node, v)
            else:
                self.tree.insert(parent, "end", text=f"[{idx}]", values=(t, self._preview_value(v)), open=False)

    def _rebuild_subtree(self, node_id, obj):
        for child in self.tree.get_children(node_id):
            self.tree.delete(child)
        if isinstance(obj, dict):
            self.tree.set(node_id, "type", "dict")
            self.tree.set(node_id, "value", "")
            self._insert_dict_nodes(node_id, obj)
        elif isinstance(obj, list):
            self.tree.set(node_id, "type", "list")
            self.tree.set(node_id, "value", f"[{len(obj)}]")
            self._insert_list_nodes(node_id, obj)
        else:
            self.tree.set(node_id, "type", _infer_type_name(obj))
            self.tree.set(node_id, "value", self._preview_value(obj))

    def _preview_value(self, v, maxlen=80):
        if isinstance(v, str):
            s = v.replace("\n", "\\n")
            if len(s) > maxlen:
                s = s[: maxlen - 1] + "…"
            return s
        return repr(v)

    # ----- Selection / Editor -----
    def _selected_node(self):
        sel = self.tree.selection()
        return sel[0] if sel else None

    def _node_path(self, node_id):
        path = []
        cur = node_id
        while cur and cur != "root":
            parent = self.tree.parent(cur)
            label = self.tree.item(cur, "text")
            if label.startswith("[") and label.endswith("]"):
                path.append(int(label[1:-1]))
            else:
                path.append(label)
            cur = parent
        path.reverse()
        return path

    def _path_to_str(self, path):
        s = ""
        for p in path:
            if isinstance(p, int):
                s += f"[{p}]"
            else:
                if s: s += "."
                s += str(p)
        return s or "<root>"

    def _on_select(self, _evt=None):
        """Quando cambi selezione, prima applica le modifiche del nodo precedente,
        poi carica in editor il nuovo nodo."""
        if self._suppress_autoapply:
            return
        new_node = self._selected_node()
        new_path = self._node_path(new_node) if new_node else None
    
        # Applica le modifiche del nodo che era in editing (se diverso dal nuovo)
        if self._editing_path is not None and new_path is not None and self._editing_path != new_path:
            self._apply_from_editor(self._editing_path)
            self._autosave_temp()  # autosave su file temporaneo
    
        # Popola editor col nuovo nodo
        self._suppress_autoapply = True
        try:
            self._populate_editor()
            self._editing_path = new_path
        finally:
            self._suppress_autoapply = False
    
    

    def _on_double_click(self, _evt=None):
        node = self._selected_node()
        if not node:
            return
        path = self._node_path(node)
        target = _deep_get(self.data, path) if path else self.data
        if not isinstance(target, (dict, list)):
            self.on_apply()

    def _tree_context(self, event):
        # evita auto-apply durante la selezione forzata col tasto destro
        try:
            row = self.tree.identify_row(event.y)
            if row:
                self._suppress_autoapply = True
                try:
                    self.tree.selection_set(row)
                finally:
                    self._suppress_autoapply = False
        except Exception:
            pass
        self.ctx_menu.tk_popup(event.x_root, event.y_root)

    def _populate_editor(self):
        node = self._selected_node()
        if not node:
            self._clear_editor()
            self._editing_path = None
            return
        path = self._node_path(node)
        self.path_var.set(self._path_to_str(path))
        obj = _deep_get(self.data, path) if path else self.data
        tname = _infer_type_name(obj)
        self.type_var.set(tname)
    
        parent = self.tree.parent(node)
        parent_type = self.tree.set(parent, "type") if parent else None
    
        if not parent:
            self.key_entry.configure(state="disabled")
            self.key_var.set("")
        else:
            if parent_type == "dict":
                self.key_label.configure(text="Key:")
                self.key_entry.configure(state="normal")
                self.key_var.set(self.tree.item(node, "text"))
            elif parent_type == "list":
                self.key_label.configure(text="Index:")
                self.key_entry.configure(state="disabled")
                self.key_var.set(self.tree.item(node, "text"))
            else:
                self.key_entry.configure(state="disabled")
                self.key_var.set(self.tree.item(node, "text"))
    
        self.value_text.configure(state="normal")
        self.value_text.delete("1.0", tk.END)
        if isinstance(obj, (dict, list)):
            self.value_text.insert(tk.END, f"<{tname}>")
            self.value_text.configure(state="disabled")
        else:
            self.value_text.insert(tk.END, obj if isinstance(obj, str) else str(obj))
    
        # imposta il path correntemente in editing
        self._editing_path = path

    def _apply_from_editor(self, path):
        """Applica i contenuti dell'editor al nodo indicato da 'path' (lista di chiavi/indici),
        senza cambiare la selezione corrente. Usa la stessa logica di on_apply."""
        try:
            # oggetto/parent correnti
            cur_obj = _deep_get(self.data, path) if path else self.data
            cur_type = _infer_type_name(cur_obj)
            target_type = self.type_var.get()
    
            # Rinomina chiave se figlio di dict
            # (solo se il path corrisponde ancora alla selezione e parent è dict)
            node = self._selected_node()
            parent = self.tree.parent(node) if node else None
            parent_type = self.tree.set(parent, "type") if parent else None
            if parent and parent_type == "dict" and self._node_path(node) == path:
                old_key = self.tree.item(node, "text")
                new_key = self.key_var.get()
                if new_key != old_key and new_key:
                    ref = _deep_get(self.data, self._node_path(parent))
                    if new_key not in ref:
                        # rinomina preservando ordine
                        new_dict = {}
                        for k in list(ref.keys()):
                            if k == old_key:
                                new_dict[new_key] = ref[k]
                            else:
                                new_dict[k] = ref[k]
                        ref.clear(); ref.update(new_dict)
    
            # ---- template helpers richiesti ----
            def field_template():
                return {"bits": "", "name": "", "desc": "", "resval": ""}
    
            def register_template():
                return {
                    "name": "",
                    "desc": "",
                    "swaccess": "",
                    "hwaccess": "",
                    "fields": [field_template()],
                }
    
            def ensure_register_shape(d):
                if not isinstance(d, dict):
                    return register_template()
                d.setdefault("name", "")
                d.setdefault("desc", "")
                d.setdefault("swaccess", "")
                d.setdefault("hwaccess", "")
                f = d.get("fields")
                if not isinstance(f, list) or len(f) == 0 or not isinstance(f[0], dict):
                    d["fields"] = [field_template()]
                else:
                    f0 = d["fields"][0]
                    f0.setdefault("bits", ""); f0.setdefault("name", "")
                    f0.setdefault("desc", ""); f0.setdefault("resval", "")
                return d
    
            # ---- container / scalare ----
            if target_type in ("dict", "list"):
                if target_type == "dict":
                    new_val = ensure_register_shape(cur_obj if isinstance(cur_obj, dict) else {})
                    _deep_set(self.data, path, new_val)
                    self._just_created.add(self._path_key(path))
                else:
                    if not isinstance(cur_obj, list) or len(cur_obj) == 0:
                        new_val = [register_template()]
                    else:
                        cur_obj[0] = ensure_register_shape(cur_obj[0])
                        new_val = cur_obj
                    _deep_set(self.data, path, new_val)
                    self._just_created.add(self._path_key(path))
            else:
                # scalare
                text_val = self.value_text.get("1.0", tk.END).rstrip("\n")
                new_scalar = _parse_typed_value(text_val, target_type)
                _deep_set(self.data, path, new_scalar)
                self._just_created.add(self._path_key(path))
    
            self.unsaved = True
    
        except Exception as e:
            # niente popup durante auto-apply: evita essere invasivi durante la navigazione
            self._set_status(f"Auto-apply fallito: {e}")
    

    def _clear_editor(self):
        self.path_var.set("")
        self.key_var.set("")
        self.type_var.set("")
        self.value_text.configure(state="normal")
        self.value_text.delete("1.0", tk.END)
        self.value_text.configure(state="disabled")

    # ----- Actions -----
    def on_apply(self):
        """Applica modifiche al nodo selezionato.
    
        - Se il nodo è figlio di un dict e hai cambiato la Key: rinomina (preservando l'ordine, evitando duplicati).
        - Se cambi il tipo:
            * → dict : crea SOLO se stai convertendo da scalare (o container appena creato vuoto)
                       il template registro:
                       {
                         "name": "", "desc": "", "swaccess": "", "hwaccess": "",
                         "fields": [ { "bits": "", "name": "", "desc": "", "resval": "" } ]
                       }
            * → list : crea SOLO se stai convertendo da scalare (o container appena creato vuoto)
                       la lista con un elemento = template registro.
            * → scalare: parse dal textbox e sostituzione.
        - Non “normalizza” dict/list già esistenti su semplice selezione/click destro.
        """
        node = self._selected_node()
        if not node:
            return
    
        path = self._node_path(node)
        parent = self.tree.parent(node)
        parent_type = self.tree.set(parent, "type") if parent else None
    
        # --- 0) Helper per chiave di path e template ---
        def _path_key(path_list):
            return tuple(path_list or [])
    
        def field_template():
            return {"bits": "", "name": "", "desc": "", "resval": ""}
    
        def register_template():
            return {
                "name": "",
                "desc": "",
                "swaccess": "",
                "hwaccess": "",
                "fields": [field_template()],
            }
    
        # --- 1) Rinomina chiave se figlio di dict --------------------------------
        if parent and parent_type == "dict":
            old_key = self.tree.item(node, "text")
            new_key = self.key_var.get()
            if new_key != old_key:
                if not new_key:
                    messagebox.showerror("Chiave invalida", "La chiave non può essere vuota.")
                    return
                try:
                    ref = _deep_get(self.data, self._node_path(parent))
                    if new_key in ref:
                        messagebox.showerror("Duplicato", f"'{new_key}' esiste già.")
                        return
                    # preserva ordine
                    new_dict = {}
                    for k in list(ref.keys()):
                        if k == old_key:
                            new_dict[new_key] = ref[k]
                        else:
                            new_dict[k] = ref[k]
                    ref.clear()
                    ref.update(new_dict)
                    self.tree.item(node, text=new_key)
                    self.unsaved = True
                except Exception as e:
                    messagebox.showerror("Errore rinomina", str(e))
                    return
    
        # --- 2) Cambi tipo / valore ----------------------------------------------
        try:
            cur_obj = _deep_get(self.data, path) if path else self.data
            cur_type = _infer_type_name(cur_obj)
            target_type = self.type_var.get()
            pkey = _path_key(path)
            just_created = hasattr(self, "_just_created") and (pkey in self._just_created)
    
            # ---- Container target: dict / list ----
            if target_type in ("dict", "list"):
                if target_type == "dict":
                    creating = not isinstance(cur_obj, dict)  # conversione da scalare
                    if creating:
                        # crea nuovo dict con template
                        new_val = register_template()
                        _deep_set(self.data, path, new_val)
                        # marca come appena creato
                        if hasattr(self, "_just_created"):
                            self._just_created.add(pkey)
                            just_created = True
                    else:
                        # già dict: NON toccare, a meno che sia stato appena creato ed è vuoto
                        if just_created and (not isinstance(cur_obj, dict) or len(cur_obj) == 0):
                            new_val = register_template()
                            _deep_set(self.data, path, new_val)
                        else:
                            new_val = cur_obj
    
                    # Aggiorna UI
                    self.tree.set(node, "type", "dict")
                    self.tree.set(node, "value", "")
                    self._rebuild_subtree(node, new_val)
                    self.tree.item(node, open=True)
    
                    # Se nuovo, metti il focus su 'name'
                    if just_created:
                        try:
                            for child in self.tree.get_children(node):
                                if self.tree.item(child, "text") == "name":
                                    self.tree.selection_set(child)
                                    self.tree.see(child)
                                    self._populate_editor()
                                    self.key_entry.configure(state="disabled")
                                    self.value_text.configure(state="normal")
                                    self.value_text.focus_set()
                                    break
                        except Exception:
                            pass
    
                    # Editor tag
                    self.value_text.configure(state="normal")
                    self.value_text.delete("1.0", "end")
                    self.value_text.insert("end", "<dict>")
                    self.value_text.configure(state="disabled")
    
                    self.unsaved = True
                    self._refresh_title()
                    self._set_status("Creato dict (template registro)." if creating else "Dict aggiornato.")
                    return
    
                else:  # target_type == "list"
                    creating = not isinstance(cur_obj, list)
                    if creating:
                        # crea nuova list con un registro
                        new_val = [register_template()]
                        _deep_set(self.data, path, new_val)
                        if hasattr(self, "_just_created"):
                            self._just_created.add(pkey)
                            just_created = True
                    else:
                        # già list: NON toccare, a meno che sia appena creata ed è vuota
                        if just_created and (not isinstance(cur_obj, list) or len(cur_obj) == 0):
                            new_val = [register_template()]
                            _deep_set(self.data, path, new_val)
                        else:
                            new_val = cur_obj
    
                    # Aggiorna UI
                    self.tree.set(node, "type", "list")
                    self.tree.set(node, "value", f"[{len(new_val)}]")
                    self._rebuild_subtree(node, new_val)
                    self.tree.item(node, open=True)
    
                    # Se nuova, focus su first.name
                    if just_created:
                        try:
                            first = self.tree.get_children(node)[0]
                            self.tree.item(first, open=True)
                            for child in self.tree.get_children(first):
                                if self.tree.item(child, "text") == "name":
                                    self.tree.selection_set(child)
                                    self.tree.see(child)
                                    self._populate_editor()
                                    self.key_entry.configure(state="disabled")
                                    self.value_text.configure(state="normal")
                                    self.value_text.focus_set()
                                    break
                        except Exception:
                            pass
    
                    # Editor tag
                    self.value_text.configure(state="normal")
                    self.value_text.delete("1.0", "end")
                    self.value_text.insert("end", "<list>")
                    self.value_text.configure(state="disabled")
    
                    self.unsaved = True
                    self._refresh_title()
                    self._set_status("Creata list con primo registro." if creating else "List aggiornata.")
                    return
    
            # ---- Target scalare: string/int/float/bool/null ----
            text_val = self.value_text.get("1.0", tk.END).rstrip("\n")
            new_scalar = _parse_typed_value(text_val, target_type)
            _deep_set(self.data, path, new_scalar)
    
            # Tree update
            self.tree.set(node, "type", _infer_type_name(new_scalar))
            self.tree.set(node, "value", self._preview_value(new_scalar))
            # se prima era container, ripulisci subtree
            if cur_type in ("dict", "list"):
                self._rebuild_subtree(node, new_scalar)
    
            self.unsaved = True
            self._refresh_title()
            self._set_status("Valore aggiornato.")
    
        except Exception as e:
            messagebox.showerror("Errore Apply", f"Impossibile applicare:\n{e}")
            return
    
    
    def on_add_child(self):
        node = self._selected_node() or "root"
        path = self._node_path(node) if node != "root" else []
        target = _deep_get(self.data, path) if path else self.data
    
        try:
            if isinstance(target, dict):
                # (comportamento attuale) aggiungi chiave unica
                base = "new_key"
                key = base
                n = 1
                while key in target:
                    n += 1
                    key = f"{base}_{n}"
                target[key] = ""
                new_id = self.tree.insert(node, "end", text=key, values=("string", ""), open=False)
                self.tree.selection_set(new_id)
                self.tree.see(new_id)
                self._populate_editor()
                self.key_entry.focus_set()
                self.key_entry.select_range(0, tk.END)
                self.unsaved = True
    
            elif isinstance(target, list):
                # (comportamento attuale) aggiungi elemento
                target.append("")
                idx = len(target) - 1
                new_id = self.tree.insert(node, "end", text=f"[{idx}]", values=("string", ""), open=False)
                self.tree.selection_set(new_id)
                self.tree.see(new_id)
                self._populate_editor()
                self.value_text.configure(state="normal")
                self.value_text.focus_set()
                self.unsaved = True
    
            else:
                # SCALARE → converti al volo in dict con un placeholder
                new_val = {"new_key": ""}
                _deep_set(self.data, path, new_val)
                # aggiorna albero
                self.tree.set(node, "type", "dict")
                self.tree.set(node, "value", "")
                self._rebuild_subtree(node, new_val)
                self.tree.item(node, open=True)
                # seleziona il placeholder per rinomina
                child = self.tree.get_children(node)[0]
                self.tree.selection_set(child)
                self.tree.see(child)
                self._populate_editor()
                self.key_entry.configure(state="normal")
                self.key_entry.focus_set()
                self.key_entry.select_range(0, tk.END)
                self.unsaved = True
    
        except Exception as e:
            messagebox.showerror("Errore Add", str(e))
            return
    
        self._refresh_title()
        self._refresh_container_node(node)
    
    def on_delete(self):
        node = self._selected_node()
        if not node or node == "root":
            return
        if not messagebox.askyesno("Conferma", "Eliminare questo nodo?"):
            return
        path = self._node_path(node)
        parent = self.tree.parent(node)
        parent_path = self._node_path(parent) if parent else []
        try:
            _deep_del(self.data, path)
            parent_obj = _deep_get(self.data, parent_path) if parent_path else self.data
            self._rebuild_subtree(parent, parent_obj)
            self.tree.selection_set(parent)
            self.unsaved = True
            self._set_status("Nodo eliminato.")
        except Exception as e:
            messagebox.showerror("Errore Delete", str(e))
        self._refresh_title()

    def on_move(self, delta):
        node = self._selected_node()
        if not node or node == "root":
            return
        parent = self.tree.parent(node)
        if not parent:
            return
        parent_path = self._node_path(parent)
        try:
            parent_obj = _deep_get(self.data, parent_path)
        except Exception:
            parent_obj = None
        if not isinstance(parent_obj, list):
            self._set_status("Move disponibile solo per elementi di lista.")
            return

        label = self.tree.item(node, "text")
        try:
            idx = int(label.strip("[]"))
        except Exception:
            self._set_status("Indice lista non riconosciuto.")
            return

        new_idx = _move_in_list(self.data, parent_path, idx, delta)
        if new_idx == idx:
            return

        self._rebuild_subtree(parent, _deep_get(self.data, parent_path))
        try:
            new_id = self.tree.get_children(parent)[new_idx]
            self.tree.selection_set(new_id)
            self.tree.see(new_id)
            self._populate_editor()
        except Exception:
            pass

        self.unsaved = True
        self._refresh_title()
        self._set_status("Elemento spostato.")

    def on_rename(self):
        node = self._selected_node()
        if not node:
            return
        parent = self.tree.parent(node)
        if not parent:
            return
        if self.tree.set(parent, "type") != "dict":
            self._set_status("Rinomina disponibile solo per figli di un dict.")
            return
        self._populate_editor()
        self.key_entry.configure(state="normal")
        self.key_entry.focus_set()
        self.key_entry.select_range(0, tk.END)

    def _refresh_container_node(self, node_id):
        t = self.tree.set(node_id, "type")
        if t == "list":
            self.tree.set(node_id, "value", f"[{len(self.tree.get_children(node_id))}]")

    def _set_status(self, text):
        name = os.path.basename(self.file_path) if self.file_path else "Untitled"
        parser = "HJSON" if HJSON_AVAILABLE else "JSON-only"
        self.status.config(text=f"{text}    |    File: {name}    |    Parser: {parser}")

    def _refresh_title(self):
        star = " *" if self.unsaved else ""
        name = os.path.basename(self.file_path) if self.file_path else "Untitled"
        self.title(f"{APP_TITLE} — {name}{star}")


if __name__ == "__main__":
    if not HJSON_AVAILABLE:
        sys.stderr.write("Suggerito: `pip install hjson` per compatibilità con commenti/multiline.\n")
    if not HAS_BOOTSTRAP:
        sys.stderr.write("Opzionale: `pip install ttkbootstrap` per tema moderno (dark/light).\n")
    app = App()
    app.mainloop()

