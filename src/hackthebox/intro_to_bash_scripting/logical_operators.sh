#!/bin/bash

if [[ -e "$1" && -r "$1" ]]
then
	echo -e "The file $1 exists and has read permissions"
	exit 0
elif [[ ! -e "$1" ]]
then
	echo -e "The file $1 does not exist"
	exit 2
elif [[ ! -r "$1" ]]
then
	echo -e "The file $1 exists, but does not have read permissions"
	exit 1
else
	echo -e "Error occured."
	exit 5
fi

