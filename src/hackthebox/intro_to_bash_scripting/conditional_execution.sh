#!/bin/bash

# ––– if-else-fi ––– #

if [ $# -eq 0 ]
then 
	echo -e "You need to specify the target domain.\n"
	echo -e "Usage:\t$0 <domain>"
	exit 1
else
	domain=$1
fi

# ––– if-only ––– #

value=$1

if [ $value -gt 10 ]
then 
	echo "Given arg is greater than 10"
fi

# ––– if-elif-else ––– #

value2=$2

if ((value2 > 10)) # using (()) to put in c-style operators and sytanx
then
	echo "Given arg2 is greater than 10"
elif [ $value2 -le 10 ]
then
	echo "Given arg2 is less than or equal to 10"
else 
	echo "given arg2 is not a number"
fi

# Op	| Meaning #
# -eq	| equal
# -ne	| not equal
# -lt	| less than
# -le	| less than or equal to
# -gt	| greater than
# -ge	| greater than or equal to
#
# strings
# =	| equal to
# ==	| equal to
# !=	| not equal to
# < or >| lexicographical ordering
#
#
