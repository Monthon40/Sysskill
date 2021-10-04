#!/bin/bash

var=$(du -s -m "$1" | cut -f1)

b=1
c=20

#if (($var <= $b)); then
#	echo "Low"
#else
#	echo "High"
#fi


if [ $var -lt $b -o $var == $b ]; then      #< and =
	echo "Low"
	
elif [ $var -gt $b -a $var -lt $c ]; then                  # > and <
	echo "medium"
else
	echo "High"
	echo "$1" >> ~/ListOfBigDirs.txt
fi



