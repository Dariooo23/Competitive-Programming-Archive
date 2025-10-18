#Karol Dziekan
read -r N

for ((i = 1; i <= N; i++)); do
    if [[ $i -eq N ]]; then
        echo "$i"  
    else
        echo -n "$i "
    fi
done