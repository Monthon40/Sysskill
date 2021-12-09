#!/bin/bash

sed -n '623,641p;642q' "$1" | awk 'NR % 2 == 1' | sed 's/[|,0-9,.,{}]//g' | cut -c 6-

#new and correct version--

#!/bin/bash

tttf=$(curl -L https://en.wikipedia.org/wiki/World_Happiness_Report?action=raw)

fin=$(echo "$tttf" | grep -n '| 1||{{flag|Finland}}||7.632||1.305||1.592||0.874||0.681||0.202||0.393' | cut -d ':' -f 1)
end=$(echo "$tttf" | grep -n '| 10||{{flag|Australia}}||7.272||1.340||1.573||0.910||0.647||0.361||0.302' | cut -d ':' -f 1)
ttt=$(echo "$tttf" | sed -n "$(($fin-14))","$end p" | cut -d '|' -f 5 | sed '/^\s*$/d' | while read line; do sed 's/}//g'; done)
echo "$ttt"


	
