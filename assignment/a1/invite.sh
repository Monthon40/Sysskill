#!/bin/bash
#collaborator: Rathanon

ttt="$1"
IFS=','

while read Name Surname Year; do
	year=$( echo $Year | cut -f3 | cut -c-4)
	
	if [[ 2002 == "$year" || 2002 -gt "$year" ]] && [[ "$year" -gt 1882 ]]; then	
		echo "Dear Mr/Mrs $Surname, $Name"
	elif [[ 2545 == "$year" || 2545 -gt "$year" ]] && [[ "$year" -gt 2425 ]]; then
		echo "Dear Mr/Mrs $Surname, $Name"	
	fi
	
done < $ttt





