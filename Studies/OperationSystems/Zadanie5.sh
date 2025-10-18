#!/bin/bash

os_list=("I used Windows" "I used MacOS" "I used Linux" "I must try BSD.")

for os in "${os_list[@]}"; do
    echo "$os"
done