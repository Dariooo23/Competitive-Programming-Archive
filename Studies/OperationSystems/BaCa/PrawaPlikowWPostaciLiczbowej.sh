#Karol Dziekan
#!/bin/bash

while read -r linia; do
    if [[ $linia == total* ]]; then
        continue
    fi

    kolumny=($(echo "$linia" | awk '{$1=$1; print}'))
    prawa=${kolumny[0]}
    typ_pliku=${prawa:0:1}
    prawa=${prawa:1:9}

    zmien_na_liczbe() {
        local prawa=$1
        local wartosc=0
        [[ ${prawa:0:1} == "r" ]] && ((wartosc+=4))
        [[ ${prawa:1:1} == "w" ]] && ((wartosc+=2))
        [[ ${prawa:2:1} == "x" ]] && ((wartosc+=1))
        echo "$wartosc"
    }

    user=$(zmien_na_liczbe "${prawa:0:3}")
    group=$(zmien_na_liczbe "${prawa:3:3}")
    others=$(zmien_na_liczbe "${prawa:6:3}")

    nazwa_pliku="${kolumny[@]:8}"

    if [[ $typ_pliku == "d" ]]; then
        nazwa_pliku="$nazwa_pliku/"
    elif [[ $typ_pliku == "-" && ${prawa:2:1} == "x" ]]; then
        nazwa_pliku="$nazwa_pliku*"
    fi

    echo "$nazwa_pliku $user$group$others"
done