#!/bin/bash

var="8dm7KsjU28B7v621Jls"
value="ERmFRMVZ0U2paTlJYTkxDZz09Cg"

for i in {1..40}
do
	var=$(echo $var | base64 -b76)

	if [[ "$var" == *"$value"* && $(echo $var | wc -c) -gt 113450 ]]
	then
		echo $(echo $var | tail -c 20)
	fi

done
