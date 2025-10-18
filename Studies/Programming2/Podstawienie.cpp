//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct struktura{
    string napis;
    int liczba;
    char znak;
};

int main(){
    //Sposob 1
    struktura zmienna_struktura {"napis", 1, 'a'};

    //Sposob 2
    struktura zmienna_struktura2;
    zmienna_struktura2 = {"napis", 1, 'a'};

    //Sposob 3
    struktura zmienna_struktura3;
    zmienna_struktura3.napis = "napis";
    zmienna_struktura3.liczba = 1;
    zmienna_struktura3.znak = 'a';

    //Sposob 4
    struktura zmienna_struktura4;
    zmienna_struktura4 = struktura{"napis", 1, 'a'};

    //Sposob 5
    struktura* wskaznik_struktura5 = new struktura{"napis", 1, 'a'};
    delete wskaznik_struktura5;

    //Sposob 6
    struktura zmienna_struktura6 {"napis", 1, 'a'};
    struktura zmienna_struktura6_kopia;

    zmienna_struktura6_kopia = zmienna_struktura6;

    //Sposob 7 
    struktura* wskaznik_struktura7;
    wskaznik_struktura7 -> napis = "napis";
    wskaznik_struktura7 -> liczba = 1;
    wskaznik_struktura7 -> znak = 'a';
    return 0;
}
