#!/bin/bash

if [ "$#" != "1" ]; then
	echo "error: Invalid argument"
	exit
fi

n=$1 
while [ "$n" -ge "0" ]; do
	if [ "$n" -lt "10" ]
		then mkdir -p "ex0$n"
	else
		mkdir -p "ex$n"
	fi
	n=`expr "$n" - 1`;
done
