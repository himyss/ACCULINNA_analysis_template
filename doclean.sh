#!/bin/bash

if [ -d "build" ]; then
	rm -rf build/*
fi

if [ -d "install" ]; then
	rm -rf install/*
fi

echo -e "\e[1m\e[32mCleanup finished.\e[0m"
