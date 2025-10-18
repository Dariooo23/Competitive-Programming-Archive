#Karol Dziekan
#!/bin/bash

declare -A licznik
declare -a kolejnosc

while read -r linia; do
    [[ -z $linia ]] && continue

    if [[ -z "${licznik[$linia]}" ]]; then
        kolejnosc+=("$linia")
    fi

    ((licznik[$linia]++))
done

min_id=""
min_val=999999

for id in "${kolejnosc[@]}"; do
    count=${licznik[$id]}
    if (( count < min_val )); then
        min_val=$count
        min_id=$id
    fi
done

echo "$min_id $min_val"