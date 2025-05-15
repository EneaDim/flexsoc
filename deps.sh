#!/bin/bash

install_ip_dependencies() {
    echo
    echo "|**********************************************************************************|"
    echo "|                               Dependecies                                        |"
    echo "|**********************************************************************************|"
    echo
    cd
    sudo apt update
    sudo apt upgrade
    sudo apt-get install build-essential clang bison flex nodejs npm \
    	libreadline-dev gawk tcl-dev libffi-dev git autoconf snapd \
    	curl graphviz xdot pkg-config libboost-system-dev help2man \
    	libboost-python-dev libboost-filesystem-dev zlib1g-dev --assume-yes
    echo "|**********************************************************************************|"
    echo "|                               Installing iverilog                                |"
    echo "|**********************************************************************************|"
    echo
    sudo apt-get install -y iverilog --assume-yes
    echo "|**********************************************************************************|"
    echo "|                                Installing gtkwave                                |"
    echo "|**********************************************************************************|"
    echo
    cd
    sudo apt install gtkwave --assume-yes
    echo
    echo
    echo "|**********************************************************************************|"
    echo "|                                Installing sv2v                                   |"
    echo "|**********************************************************************************|"
    echo
    cd
    curl -sSL https://get.haskellstack.org/ | sh
    git clone https://github.com/zachjs/sv2v.git
    cd sv2v
    make
    echo
    echo
    echo "|**********************************************************************************|"
    echo "|                                Installing verilator                              |"
    echo "|**********************************************************************************|"
    echo
    cd
    git clone https://github.com/verilator/verilator
    cd verilator
    git pull
    autoconf
    ./configure
    make -j 2
    sudo make install
    echo
    echo "|**********************************************************************************|"
    echo "|            Cloning yosys and then will start the installation of yosys           |"
    echo "|**********************************************************************************|"
    echo
    cd
    git clone https://github.com/YosysHQ/yosys.git
    cd yosys
    git submodule update --init
    make -j 2
    sudo make install
    cd
    echo
    echo "|**********************************************************************************|"
    echo "|                              OpenSTA installation                                |"
    echo "|**********************************************************************************|"
    cd 
    echo "| Download https://github.com/davidkebo/cudd/blob/main/cudd_versions/cudd-3.0.0.tar.gz |"
    tar xvfz cudd-3.0.0.tar.gz
    cd cudd-3.0.0
    ./configure --prefix=/usr/local/bin
    make -j 2
    sudo make install
    cd
    sudo apt install cmake swig libeigen3-dev
    git clone https://github.com/The-OpenROAD-Project/OpenSTA.git
    cd OpenSTA
    mkdir build
    cd build
    cmake -DCUDD_DIR=/usr/local/bin/lib
    echo "|**********************************************************************************|"
    echo "|                                Installing netlistsvg                             |"
    echo "|**********************************************************************************|"
    echo
    cd
    sudo npm install -g nturley/netlistsvg
    echo
}

install_soc_dependencies() {
    echo "|**********************************************************************************|"
    echo "|                              RISCV GNU toolchain                                 |"
    echo "|**********************************************************************************|"
    cd 
    sudo mkdir /opt/riscv32
    sudo apt-get install srecord autoconf automake autotools-dev curl python3 python3-pip python3-tomli \
    	libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool \
    	patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev
    git clone https://github.com/riscv/riscv-gnu-toolchain --recursive
    cd riscv-gnu-toolchain
    mkdir build
    cd build
    ../configure --prefix=/opt/riscv --with-arch=rv32gc --with-abi=ilp32d
    sudo make -j 2
    sudo make install
}

case "$1" in
    ip)
        install_ip_dependencies
        ;;
    soc)
        install_soc_dependencies
        ;;
    *)
        install_ip_dependencies
        install_soc_dependencies
        ;;
esac

