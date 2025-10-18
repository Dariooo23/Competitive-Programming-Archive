#!/bin/bash

sum=0
count=0

while read number; do
    sum=$((sum + number))
    count=$((count + 1))
done

if [ "$count" ne 0 ]; then
    average=$((sum / count))
    echo "$average"
else
    echo "0"
fi