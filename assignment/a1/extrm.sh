#!/bin/bash

cd "$2"
for ttt in *.$1; do 
	mv "$ttt" "${ttt%.$1}"	
done
	


