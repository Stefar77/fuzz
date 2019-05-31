#!/bin/sh

seed=16020 

while [ true ]
do
 seed=$(expr $seed + 1)
 echo -n "${seed}, "

 timeout -s 9 -k 2 --foreground 1 ./fuzz2 $seed

done
