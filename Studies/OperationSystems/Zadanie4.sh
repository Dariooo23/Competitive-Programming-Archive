#!/bin/bash

echo "What is your favorite OS?"
read os

if [[ "$os" == "Windows" ]]; then
    echo "I used Windows once. What is that blue screen for?"
elif [[ "$os" == "MacOS" ]]; then
    echo "Your OS can do anything as long as it is in AppStore."
elif [[ "$os" == "Linux" ]]; then
    echo "Linux is free if your time is worthless."
else
    echo "Is $os an operating system?"
fi