#!/bin/bash

if [ -e $1 ]
then
	echo -e "File $1 exists"
	exit 0
else
	echo -e "File $1 doesn't exist"
	exit 1
fi

