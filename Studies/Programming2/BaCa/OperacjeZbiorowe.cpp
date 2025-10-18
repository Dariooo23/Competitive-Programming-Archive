//Karol Dziekan

#include <iostream>

using namespace std;

bool Equality (int zbior1, int zbior2){
    if (zbior1 == zbior2){
        return 1;
    }else{
        return 0;
    }
}

int Cardinality (int zbior){
    int licznosc = 0;
    if(zbior&(1<<0))licznosc++;
    if(zbior&(1<<1))licznosc++;
    if(zbior&(1<<2))licznosc++;
    if(zbior&(1<<3))licznosc++;
    if(zbior&(1<<4))licznosc++;
    if(zbior&(1<<5))licznosc++;
    if(zbior&(1<<6))licznosc++;
    if(zbior&(1<<7))licznosc++;
    if(zbior&(1<<8))licznosc++;
    if(zbior&(1<<9))licznosc++;
    if(zbior&(1<<10))licznosc++;
    if(zbior&(1<<11))licznosc++;
    if(zbior&(1<<12))licznosc++;
    if(zbior&(1<<13))licznosc++;
    if(zbior&(1<<14))licznosc++;
    if(zbior&(1<<15))licznosc++;
    if(zbior&(1<<16))licznosc++;
    if(zbior&(1<<17))licznosc++;
    if(zbior&(1<<18))licznosc++;
    if(zbior&(1<<19))licznosc++;
    if(zbior&(1<<20))licznosc++;
    if(zbior&(1<<21))licznosc++;
    if(zbior&(1<<22))licznosc++;
    if(zbior&(1<<23))licznosc++;
    if(zbior&(1<<24))licznosc++;
    if(zbior&(1<<25))licznosc++;
    if(zbior&(1<<26))licznosc++;
    if(zbior&(1<<27))licznosc++;
    if(zbior&(1<<28))licznosc++;
    if(zbior&(1<<29))licznosc++;
    if(zbior&(1<<30))licznosc++;
    if(zbior&(1<<31))licznosc++;
    return licznosc;
}

void Complement (int zbior1, int* zbior2){
    *zbior2 = (~zbior1);
    return;
}

void Union (int zbior1, int zbior2, int* zbior_suma){
    *zbior_suma = (zbior1 | zbior2);
    return;
}

void Intersection (int zbior1, int zbior2, int* zbior_przeciecie){
    *zbior_przeciecie = (zbior1 & zbior2);
    return;
}

void Difference (int zbior1, int zbior2, int* zbior_roznica){
 	*zbior_roznica = (zbior1 & (~zbior2));
    return;
}

void Symmetric (int zbior1, int zbior2, int* zbior_symetryczny){
	*zbior_symetryczny =  (zbior1 ^ zbior2);
    return;
}

bool LessThan (int zbior1, int zbior2){
	int rozmiar1 = Cardinality (zbior1);
	int rozmiar2 = Cardinality (zbior2);

	if (rozmiar1 == rozmiar2){
        if (zbior1 < 0 && zbior2 < 0){
            if (zbior1&(~(1<<31)) < zbior2&(~(1<<31))){
                return 1;
            }else{
                return 0;
            }
        }else{
            if (zbior1 < 0){
                return 0;
            }else{
                if (zbior2 < 0){
                    return 1;
                }else{
                    return zbior1 < zbior2;
                }
            }
        }
	}else{
        if (rozmiar1 < rozmiar2 ){
		    return 1;
	    }else{
            return 0;
        }
    }
}

bool LessEqual (int zbior1, int zbior2){
	return LessThan (zbior1, zbior2) || Equality(zbior1, zbior2);
}

bool GreatEqual (int zbior1, int zbior2){
	return LessEqual (zbior2, zbior1);
}

bool GreatThan (int zbior1, int zbior2){
	return LessThan (zbior2, zbior1);
}

bool Inclusion (int zbior1, int zbior2){
    int rozmiar1 = Cardinality (zbior2);
    int rozmiar2 = Cardinality (zbior1 | zbior2);

    if (rozmiar1 == rozmiar2){
        return 1;
    }else{
        return 0;
    }
}

bool Conjunctive (int zbior1, int zbior2){
    if (zbior1 & zbior2){
        return 1;
    }else{
        return 0;
    }
}

bool Disjoint (int zbior1, int zbior2){
    if (zbior1 & zbior2){
        return 0;
    }else{
        return 1;
    }
}

bool Member (char* ciag, int zbior){
    if (*ciag == ' '){
        return Member (ciag + 1, zbior);
    }else{
        int suma = 0;
        suma += (*(ciag++) - '0') * 16;
        suma += (*(ciag++) - '0') * 8;
        suma += (*(ciag++) - '0') * 4;
        suma += (*(ciag++) - '0') * 2;
        suma += (*(ciag++) - '0') * 1;

        if (zbior & (1<<suma)){
            return 1;
        }else{
            return 0;
        }
    }
}

void Print (int zbior, char* ciag){
    int flaga = 0;
    if (zbior & (1<<31)){*(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<30)){*(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<29)){*(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<28)){*(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<27)){*(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<26)){*(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<25)){*(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<24)){*(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<23)){*(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<22)){*(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<21)){*(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<20)){*(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<19)){*(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<18)){*(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<17)){*(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<16)){*(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<15)){*(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<14)){*(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<13)){*(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<12)){*(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<11)){*(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<10)){*(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<9)) {*(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<8)) {*(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<7)) {*(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<6)) {*(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<5)) {*(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<4)) {*(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<3)) {*(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<2)) {*(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<1)) {*(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '1'; *(ciag++) = ' '; flaga = 1;}
    if (zbior & (1<<0)) {*(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = '0'; *(ciag++) = ' '; flaga = 1;}
    if (flaga == 0)     {*(ciag++) = 'e'; *(ciag++) = 'm'; *(ciag++) = 'p'; *(ciag++) = 't'; *(ciag++) = 'y';}
    *ciag = '\0';
    
    return;
}

bool Emptiness (int zbior){
    if (zbior == 0){
        return 1;
    }else{
        return 0;
    }
}

bool Nonempty (int zbior){
    return !Emptiness(zbior);
}

void Emplace_Rek (char* ciag, int* zbior){
    if (*ciag == '\0'){
        return;
    }
    if (*ciag == ' '){
        Emplace_Rek (ciag + 1, zbior);
    }else{
        int suma = 0;

        suma += ((*(ciag++) - '0') * 16);
        suma += ((*(ciag++) - '0') * 8);
        suma += ((*(ciag++) - '0') * 4);
        suma += ((*(ciag++) - '0') * 2);
        suma += ((*(ciag++) - '0') * 1);

        int przesuniecie = (1 << suma);
        
        *zbior = (*zbior | przesuniecie);

        Emplace_Rek (ciag, zbior);
    }

    return;
}

void Emplace (char* ciag, int* zbior){
    *zbior = 0;

    Emplace_Rek (ciag, zbior);

    return;
}

void Insert (char* ciag, int* zbior){
    Emplace_Rek (ciag, zbior);
    return;
}

void Erase (char* ciag, int* zbior){
    if (*ciag == '\0'){
        return;
    }

    if (*ciag == ' '){
        Erase (ciag + 1, zbior);
    }else{
        int suma = 0;

        suma += ((*(ciag++) - '0') * 16);
        suma += ((*(ciag++) - '0') * 8);
        suma += ((*(ciag++) - '0') * 4);
        suma += ((*(ciag++) - '0') * 2);
        suma += ((*(ciag++) - '0') * 1);

        *zbior = ((*zbior) & (~(1 << suma)));

        Erase (ciag, zbior);
    }

    return;
}
int main(){
    cout << GreatThan(2,1);
}