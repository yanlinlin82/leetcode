#!/bin/bash

if [ -z "$1" ]; then
	echo "Usage: $0 <xxx.cpp>"
	exit 1
fi

g++ -std=c++17 $1 && ./a.out && rm -f ./a.out
