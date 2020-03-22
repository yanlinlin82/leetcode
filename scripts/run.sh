#!/bin/bash

DEBUG=0
if [ "$1" == "-d" ]; then
	DEBUG=1
	shift
fi

if [ -z "$1" ]; then
	echo "Usage: $0 [-d] <xxx.cpp>"
	exit 1
fi

if [ "$DEBUG" == "0" ]; then
	g++ -O3 -std=c++17 $1 && ./a.out && rm -f ./a.out
else
	g++ -g -std=c++17 $1 && gdb ./a.out && rm -f ./a.out
fi
