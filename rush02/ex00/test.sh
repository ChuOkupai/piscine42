#!/bin/bash

if [ "$#" != "1" ]; then
	echo "error: Invalid argument"
	exit
fi

n=$1 
while [ "$n" -ge "0" ]; do
	./rush-02 $n
	n=`expr "$n" - 1`;
done
