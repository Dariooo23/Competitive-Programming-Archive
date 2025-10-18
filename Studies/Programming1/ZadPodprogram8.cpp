//Karol Dziekan
#include <iostream>

using namespace std;

void liczba_slownie (int liczba){
    if (liczba < 0){
        liczba = liczba * -1;
        cout << "minus ";
    }

    int jednosci = liczba % 10;
    liczba = liczba / 10;
    int dziesiatki = liczba % 10;
    liczba = liczba / 10;
    int setki = liczba % 10;
    liczba = liczba / 10;
    int jednosci_tysiecy = liczba % 10;
    liczba = liczba / 10;
    int dziesiatki_tysiecy = liczba % 10;
    liczba = liczba / 10;

    //Tysiace
    switch(dziesiatki_tysiecy){
        case 0:
            switch(jednosci_tysiecy){
                case 0:
                    break;
                case 1:
                    cout << "jeden ";
                    break;
                case 2:
                    cout << "dwa ";
                    break;
                case 3:
                    cout << "trzy ";
                    break;
                case 4:
                    cout << "cztery ";
                    break;
                case 5:
                    cout << "piec ";
                    break;
                case 6:
                    cout << "szesc ";
                    break;
                case 7:
                    cout << "siedem ";
                    break;
                case 8:
                    cout << "osiem ";
                    break;
                case 9:
                    cout << "dziewiec ";
                    break;
            }
            break;
        case 1:
            switch(jednosci_tysiecy){
                case 0:
                    cout << "dziesiec ";
                    break;
                case 1:
                    cout << "jedenascie ";
                    break;
                case 2:
                    cout << "dwanascie ";
                    break;
                case 3:
                    cout << "trzynascie ";
                    break;
                case 4:
                    cout << "czternascie ";
                    break;
                case 5:
                    cout << "pietnascie ";
                    break;
                case 6:
                    cout << "szesnascie ";
                    break;
                case 7:
                    cout << "siedemnascie ";
                    break;
                case 8:
                    cout << "osiemnascie ";
                    break;
                case 9:
                    cout << "dziewietnascie ";
                    break;
            }
            break;
        case 2: 
            cout << "dwadziescia ";
            break;
        case 3: 
            cout << "trzydziesci ";
            break;
    }

    if(dziesiatki_tysiecy == 2 || dziesiatki_tysiecy == 3){
        switch(jednosci_tysiecy){
                case 0:
                    break;
                case 1:
                    cout << "jeden ";
                    break;
                case 2:
                    cout << "dwa ";
                    break;
                case 3:
                    cout << "trzy ";
                    break;
                case 4:
                    cout << "cztery ";
                    break;
                case 5:
                    cout << "piec ";
                    break;
                case 6:
                    cout << "szesc ";
                    break;
                case 7:
                    cout << "siedem ";
                    break;
                case 8:
                    cout << "osiem ";
                    break;
                case 9:
                    cout << "dziewiec ";
                    break;
            }
    }


    if(jednosci_tysiecy == 1 && dziesiatki_tysiecy == 0){
        cout << "tysiac ";
    }
    if((jednosci_tysiecy == 0 || jednosci_tysiecy == 1) && (dziesiatki_tysiecy == 2 || dziesiatki_tysiecy == 3)){
        cout << "tysiecy ";
    }
    if(jednosci_tysiecy > 1 && jednosci_tysiecy < 5  && dziesiatki_tysiecy != 1){
        cout << "tysiace ";
    }
    if(jednosci_tysiecy >= 5 || dziesiatki_tysiecy == 1){
        cout << "tysiecy ";
    }

    //Setki
    switch(setki){
        case 0:
            break;
        case 1:
            cout << "sto ";
            break;
        case 2:
            cout << "dwiescie ";
            break;
        case 3:
            cout << "trzysta ";
            break;
        case 4:
            cout << "czterysta ";
            break;
        case 5:
            cout << "piecset ";
            break;
        case 6:
            cout << "szescset ";
            break;
        case 7:
            cout << "siedemset ";
            break;
        case 8:
            cout << "osiemset ";
            break;
        case 9:
            cout << "dziewiecset ";
            break;
    }

    //Dziesiatki
    switch(dziesiatki){
        case 0:
            break;
        case 1:
            switch(jednosci){
                case 0:
                    cout << "dziesiec ";
                    break;
                case 1:
                    cout << "jedenascie ";
                    break;
                case 2:
                    cout << "dwanascie ";
                    break;
                case 3:
                    cout << "trzynascie ";
                    break;
                case 4:
                    cout << "czternascie ";
                    break;
                case 5:
                    cout << "pietnascie ";
                    break;
                case 6:
                    cout << "szesnascie ";
                    break;
                case 7:
                    cout << "siedemnascie ";
                    break;
                case 8:
                    cout << "osiemnascie ";
                    break;
                case 9:
                    cout << "dziewietnascie ";
                    break;
            }
            break;
        case 2:
            cout << "dwadziescia ";
            break;
        case 3:
            cout << "trzydziesci ";
            break;
        case 4:
            cout << "czterdziesci ";
            break;
        case 5:
            cout << "piecdziesiat ";
            break;
        case 6:
            cout << "szescdziesiat ";
            break;
        case 7:
            cout << "siedemdziesiat ";
            break;
        case 8:
            cout << "osiemdziesiat ";
            break;
        case 9:
            cout << "dziewiecdziesiat";
            break;
    }

    //Jednosci
    if(dziesiatki != 1){
         switch(jednosci){
                case 0:
                    break;
                case 1:
                    cout << "jeden ";
                    break;
                case 2:
                    cout << "dwa ";
                    break;
                case 3:
                    cout << "trzy ";
                    break;
                case 4:
                    cout << "cztery ";
                    break;
                case 5:
                    cout << "piec ";
                    break;
                case 6:
                    cout << "szesc ";
                    break;
                case 7:
                    cout << "siedem ";
                    break;
                case 8:
                    cout << "osiem ";
                    break;
                case 9:
                    cout << "dziewiec ";
                    break;
            }
    }
}
int main(){

    int liczba = 0;
    
    cin >> liczba;

    liczba_slownie (liczba);
    
    return 0;
}