#!/bin/bash

sed -n '623,641p;642q' "$1" | awk 'NR % 2 == 1' | sed 's/[|,0-9,.,{}]//g' | cut -c 6-




	
