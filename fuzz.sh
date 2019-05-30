#!/bin/sh

while [ 0 -lt 1 ]
do
 echo -n .
 ./fuzz &
 sleep 2
 killall fuzz
done
