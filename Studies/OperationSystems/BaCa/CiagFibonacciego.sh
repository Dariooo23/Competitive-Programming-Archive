#Karol Dziekan
#!/bin/bash

read n

a=0
b=1

for ((i=1; i<=n; i++)); do
    echo "$a"
    pom=$((a + b))
    a=$b
    b=$pom
done