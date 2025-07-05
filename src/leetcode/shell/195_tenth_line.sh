#!/bin/bash

if [[ ! -e file.txt ]]
then
	echo -e "ERROR: file.txt does not exist!"
	exit 1
fi

count=0
while IFS= read -r line; do
	((++count))
	if [[ $count -eq 10 ]] 
	then
		echo -e $line
		exit 0
	fi
done < file.txt 

echo -e "Less than 10 lines!"
exit 1



