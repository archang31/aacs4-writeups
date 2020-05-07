#!/bin/bash

addr=$1
port=$2
filename=$3

if [ $# -eq 0 ]
    then
        echo "Usage: ./send.sh <ipaddr> <port> <source_file_to_test.c>"
        exit -1
fi

base64 $filename > send.tmp
echo "ENDEND" >> send.tmp
echo "." >> send.tmp

cat send.tmp | nc $addr $port
