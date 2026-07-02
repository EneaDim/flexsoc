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
    sudo apt-get install -y build-essential clang flex bison libfl-dev nodejs npm \
      libreadline-dev gawk tcl-dev libffi-dev git cmake libelf-dev autoconf swig wget \
      curl graphviz xdot pkg-config libboost-system-dev ninja-build pkg-config help2man \
      libeigen3-dev libboost-python-dev libboost-filesystem-dev zlib1g-dev automake \
      libtool m4 pkg-config gcc g++ perl unzip universal-ctags --assume-yes
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
    stack setup
    stack install
    echo
    sudo cp $HOME/.local/bin/sv2v /usr/local/bin
    echo
    echo
    echo "|**********************************************************************************|"
    echo "|                                Installing verilator                              |"
    echo "|**********************************************************************************|"
    echo
    cd
    git clone https://github.com/verilator/verilator
    cd verilator
    git checkout v5.036 
    autoconf
    ./configure --prefix=/usr
    make -j 2
    sudo make install
    echo
    cd
    echo "|**********************************************************************************|"
    echo "|               OpenROAD flow scripts - Yosys - OpenSTA                            |"
    echo "|**********************************************************************************|"
    echo
    cd
    git clone --recursive https://github.com/The-OpenROAD-Project/OpenROAD-flow-scripts openroad
    cd openroad
    sudo ./setup.sh
    sudo ./build_openroad.sh --local --threads 2 --install-path /usr/local
    echo
    cd
    echo
    echo "|**********************************************************************************|"
    echo "|                                 Yosys-Slang                                      |"
    echo "|**********************************************************************************|"
    echo
    git clone --recursive https://github.com/povik/yosys-slang
    make -j2
    sudo make install
    cd
    echo "|**********************************************************************************|"
    echo "|                                Installing netlistsvg                             |"
    echo "|**********************************************************************************|"
    echo
    cd
    sudo npm install -g nturley/netlistsvg
    echo
    rm -rf ~/sv2v ~/verilator ~/cudd-3.0.0* ~/.stack
    echo
    #&& apt-get purge -y \
    #  build-essential clang bison flex autoconf cmake pkg-config \
    #  swig help2man libboost-system-dev libboost-filesystem-dev \
    #  libboost-python-dev libeigen3-dev tcl-dev \
    #  libffi-dev libreadline-dev gawk snapd \
    #&& apt-get autoremove -y --purge
    
}

install_soc_dependencies() {
    echo "|**********************************************************************************|"
    echo "|                              RISCV GNU toolchain                                 |"
    echo "|**********************************************************************************|"
    cd 
    sudo mkdir /tools/riscv32
    sudo apt-get install srecord autoconf automake autotools-dev curl python3 python3-pip python3-tomli \
    	libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool \
    	patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev
    git clone https://github.com/riscv/riscv-gnu-toolchain --recursive
    cd riscv-gnu-toolchain
    mkdir build
    cd build
    ../configure --prefix=/tools/riscv32 --with-arch=rv32gc --with-abi=ilp32d
    sudo make -j 2
    sudo make install
    echo
    cd 
    echo
    #rm -rf ~/riscv-gnu-toolchain
    echo

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

