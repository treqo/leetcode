#!/bin/bash

if [ $# -eq 0 ]
then
	echo -e "ERROR: No argument given.\n"
	echo -e "Usage:\t$0 <string>"
	exit 1
elif [ $# -ne 1 ]
then
	echo -e "ERROR: Too many arguments given."
	echo -e "Usage:\t$0 <string>"
	exit 1
else
	var=$1
	for counter in {1..40}
	do
		var=$(echo $var | base64)
	done
fi

