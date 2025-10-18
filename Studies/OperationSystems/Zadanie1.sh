#!/bin/bash
# Skrypt mycommand.sh - wyświetla aktualną datę, katalog użytkownika oraz nazwę hosta.
# Skrypt trzeba przenieść do katalogu /usr/local/bin, aby był dostępny z każdego miejsca w systemie.

current_date=$(date)
current_directory=$(pwd)
hostname=$(hostname)

echo "Today is ${current_date}."
echo "You are in ${current_directory} @ ${hostname}"