############################################
###        Static Timing Analysis        ###
############################################

sta: setup_signoff 
	@echo "\n$(ORANGE)Static Timing Analysis...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta.tcl 2>&1 | tee \
	$(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log 
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).warnings || true 
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).errors || true 

# Write SDF
sdf: setup_signoff
	@echo "\n$(ORANGE)Write sdf files...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/sdf
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/write_sdf.tcl 2>&1 

#####################################
###        Power Analysis        ###
####################################
power: setup_signoff 
	@echo "\n$(ORANGE)Power Analysis, static and with .vcd...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl  2>&1 | tee $(LOGDIR)/$(TOP)_power.log 

# STA only violators
sta_violators: setup_signoff 
	@echo "\n$(ORANGE)Static Timing Analysis only timing violators...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta_violators.tcl > $(LOGDIR)/$(TOP)_sta.violators

# Path view of STA timing reports
path_view:
	@echo "\n$(ORANGE)Path view generation of STA report...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/path_view ;
	$(Q)$(PYTHON) $(UTILDIR)/interactiveReport.py -i $(LOGDIR)/$(PATH_VIEW_FILE) \
	-s $(UTILDIR)/default.svg -t opensta -n $(NPATHS)
	
