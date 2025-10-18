#Karol Dziekan
#!/bin/bash

read szukana_litera

dlugosc=${#szukana_litera}

if [[ $dlugosc -eq 2 ]]; then
    szukana_litera=$(echo "${szukana_litera:0:1}" | tr 'A-Z' 'a-z')
fi

while read slowo; do
    licznik=0

    if [[ $dlugosc -eq 2 ]]; then
        slowo=$(echo "$slowo" | tr 'A-Z' 'a-z')
    fi

    for (( i=0; i<${#slowo}; i++ )); do
        if [[ ${slowo:i:1} == $szukana_litera ]]; then
            ((licznik++))
        fi
    done

    echo "$licznik"
done