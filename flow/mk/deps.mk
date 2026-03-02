# DEPENDENCIES
deps:
	@echo "\n$(ORANGE)Installing dependencies for IP development ...\n$(RESET)"
	sudo apt install -y make python3 python3-pip
	sed -i 's/\r$$//' deps.sh
	bash ./deps.sh ip
	pip install -r requirements.txt
	
deps-soc:
	@echo "\n$(ORANGE)Installing dependencies for SoC integration ...\n$(RESET)"
	bash ./deps.sh soc
	echo
	export PATH=$$PATH:/tools/riscv32/bin
	echo "export PATH=/tools/riscv32/bin" >> ~/.bashrc
