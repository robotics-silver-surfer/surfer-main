#!/bin/bash
r=$((RANDOM % 1))
while(true)
do
	str=""
	for I in 1 2 3
	do
		x=$((RANDOM % 1100))
		y=$((RANDOM % 700))
		rot=$((RANDOM % 360))
		if [ $I -eq 1 ]
		then
			str="{x: $x, y: $y, rot: $rot}"
		else
			str="$str ,{x: $x, y: $y, rot: $rot}"
		fi
	done
	rostopic pub -1 Image Ref/image "{header: auto, bots: [$str]}"
done
