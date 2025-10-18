#Karol Dziekan
#!/bin/bash

suma=0
ilosc=0
liczby=()

while read -r linia; do
    if [[ -n $linia ]]; then
        liczba=$((linia))
        suma=$((suma + liczba))
        liczby+=($liczba)
        ilosc=$((ilosc + 1))
    fi
done

srednia=$((suma / ilosc))

suma_kwadratow=0
for l in "${liczby[@]}"; do
    roznica=$((l - srednia))
    kwadrat=$((roznica * roznica))
    suma_kwadratow=$((suma_kwadratow + kwadrat))
done

wariancja=$((suma_kwadratow / ilosc))

echo "$srednia"
echo "$wariancja"