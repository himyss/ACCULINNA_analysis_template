#!/bin/bash

# TODO activate/deactivate
#./doclean.sh

if [ ! -d "build" ]; then
	mkdir build
fi

if [ ! -d "install" ]; then
	mkdir install
fi

cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=../install
make -j
make install
cd -

echo -e "\e[1m\e[32mCompilation finished.\e[0m"
