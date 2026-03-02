###                  Power Analysis            ###
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
	
# Write SDF
sdf: setup_signoff
	@echo "\n$(ORANGE)Write sdf files...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/sdf
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/write_sdf.tcl > /dev/null 2>&1
