import random
import time


def Wyszukiwanie_Liniowe(tablica, szukana_liczba):
    ilosc_operacji = 0
    indeks_szukanej_liczby = -1

    for i in range (0, len(tablica)):
        ilosc_operacji += 1
        if (tablica[i] == szukana_liczba):
            indeks_szukanej_liczby = i
            break
    
    if (indeks_szukanej_liczby == -1):
        print ('Nie znaleziono')
    else:
        print ('Pozycja: ', indeks_szukanej_liczby)
        print ('Ilosc operacji: ', ilosc_operacji)




def Wyszukiwanie_Binarne(tablica, szukana_liczba):
    ilosc_operacji = 0
    indeks_szukanej_liczby = -1

    lewo = 0 
    prawo = len (tablica) - 1

    while (lewo <= prawo):
        ilosc_operacji += 1
        srodek = (lewo + prawo) // 2

        if (tablica[srodek] == szukana_liczba):
            indeks_szukanej_liczby = srodek
            break
        if (tablica[srodek] < szukana_liczba):
            lewo = srodek + 1
        else:
            prawo = srodek - 1
    
    if (indeks_szukanej_liczby == -1):
        print ('Nie znaleziono')
    else:
        print ('Pozycja: ', indeks_szukanej_liczby)
        print ('Ilosc operacji: ', ilosc_operacji)



def Wyszukiwanie_Interpolacyjne(tablica, szukana_liczba):
    ilosc_operacji = 0
    indeks_szukanej_liczby = -1

    lewo = 0 
    prawo = len (tablica) - 1

    while (lewo <= prawo and tablica[lewo] <= szukana_liczba <= tablica[prawo]):
        ilosc_operacji += 1
        srodek = lewo + ((szukana_liczba - tablica[lewo]) * (prawo - lewo) // (tablica[prawo] - tablica[lewo]))

        if (tablica[srodek] == szukana_liczba):
            indeks_szukanej_liczby = srodek
            break
        if (tablica[srodek] < szukana_liczba):
            lewo = srodek + 1
        if (tablica[srodek] > szukana_liczba):
            prawo = srodek - 1
    
    if (indeks_szukanej_liczby == -1):
        print ('Nie znaleziono')
    else:
        print ('Pozycja: ', indeks_szukanej_liczby)
        print ('Ilosc operacji: ', ilosc_operacji)





# Generowanie danych w sposob losowy i liniowy
rozmiar = int(input('Podaj rozmiar tablicy: '))

zakres = int(input('Podaj zakres liczb w tablicy: '))

tablica_losowa = [0] * rozmiar
tablica_liniowa = [0] * rozmiar

for i in range (0, rozmiar):
    tablica_losowa[i] = random.choice(range(1,zakres))

for i in range (0,rozmiar):
    tablica_liniowa[i] = i + random.choice(range(-2,2))

szukana_liczba = int(input('Podaj szukana liczbe: '))
czas_poczatek = 0
czas_koniec = 0

tablica_liniowa.sort()
tablica_losowa.sort()

print ('\n')

print ('Wyszukiwanie liniowe')
print ('Dane z tablicy losowej: ')
czas_poczatek = time.perf_counter()
Wyszukiwanie_Liniowe(tablica_losowa, szukana_liczba)
czas_koniec = time.perf_counter()
print ('Czas wykonania: ', czas_koniec - czas_poczatek)

print ()

print ('Dane z tablicy liniowej: ')
czas_poczatek = time.perf_counter()
Wyszukiwanie_Liniowe(tablica_liniowa, szukana_liczba)
czas_koniec = time.perf_counter()
print ('Czas wykonania: ', czas_koniec - czas_poczatek)

print ('\n')

print ('Wyszukiwanie binarne')
print ('Dane z tablicy losowej: ')
czas_poczatek = time.perf_counter()
Wyszukiwanie_Binarne(tablica_losowa, szukana_liczba)
czas_koniec = time.perf_counter()
print ('Czas wykonania: ', czas_koniec - czas_poczatek)

print ()

print ('Dane z tablicy liniowej: ')
czas_poczatek = time.perf_counter()
Wyszukiwanie_Binarne(tablica_liniowa, szukana_liczba)
czas_koniec = time.perf_counter()
print ('Czas wykonania: ', czas_koniec - czas_poczatek)

print ('\n')

print ('Wyszukiwanie interpolacyjne')
print ('Dane z tablicy losowej: ')
czas_poczatek = time.perf_counter()
Wyszukiwanie_Interpolacyjne(tablica_losowa, szukana_liczba)
czas_koniec = time.perf_counter()
print ('Czas wykonania: ', czas_koniec - czas_poczatek)

print ()

print ('Dane z tablicy liniowej: ')
czas_poczatek = time.perf_counter()
Wyszukiwanie_Interpolacyjne(tablica_liniowa, szukana_liczba)
czas_koniec = time.perf_counter()
print ('Czas wykonania: ', czas_koniec - czas_poczatek)

#Ponizej wyjasnienie pesymistycznego przypadku dla wyszukiwania interpolacyjnego i kilka testow programu

#Wyszukiwanie interpolacyjne w pesymistycznym przypadku dziala w czasie O(N),
#dzieje sie tak dla tablic, w ktorych wzrost wartosci na kolejnych indeksach nie jest liniowy.
#Przyklad: tablica = [1,2,3,...,999,1000,1000000000], szukana liczba = 1000
#W tym tescie, ze wzgledu na liczbe 1e9 na ostatniej pozycji, algorytm heurystycznie "przewiduje", ze szukana liczba musi byc na pozycji,
#ktora jest blisko poczatku tablicy (Poniewaz zaklada liniowy wzrost wartosci, ktory wynosilby okolo 1e6),
#tym samym wyszukiwanie przesuwa lewy zakres o 1 po kazdym sprawdzeniu, co skutkuje czasem O(N).

#Wyniki kilku testow dla wszystkich wyszukiwan:
#Pozycje znalezionych liczb moga sie roznic ze wzgledu na ich wielokrotne wystepowanie

#Test 1:
"""
Podaj rozmiar tablicy: 1000000000
Podaj zakres liczb w tablicy: 1000000
Podaj szukana liczbe: 32456


Wyszukiwanie liniowe
Dane z tablicy losowej: 
Pozycja:  32449190
Ilosc operacji:  32449191
Czas wykonania:  7.766873000015039

Dane z tablicy liniowej: 
Pozycja:  32456
Ilosc operacji:  32457
Czas wykonania:  0.00134680001065135


Wyszukiwanie binarne
Dane z tablicy losowej:
Pozycja:  32449719
Ilosc operacji:  19
Czas wykonania:  0.00011080002877861261

Dane z tablicy liniowej:
Pozycja:  32456
Ilosc operacji:  30
Czas wykonania:  0.00011570000788196921


Wyszukiwanie interpolacyjne
Dane z tablicy losowej:
Pozycja:  32450063
Ilosc operacji:  2
Czas wykonania:  0.00012229999992996454

Dane z tablicy liniowej:
Pozycja:  32456
Ilosc operacji:  2
Czas wykonania:  0.00015959999291226268"
"""

#Test 2:
"""
Podaj rozmiar tablicy: 1000000
Podaj zakres liczb w tablicy: 1000000
Podaj szukana liczbe: 34555


Wyszukiwanie liniowe
Dane z tablicy losowej: 
Pozycja:  34629
Ilosc operacji:  34630
Czas wykonania:  0.0015160000184550881

Dane z tablicy liniowej: 
Pozycja:  34555
Ilosc operacji:  34556
Czas wykonania:  0.0013271999778226018


Wyszukiwanie binarne
Dane z tablicy losowej: 
Pozycja:  34631
Ilosc operacji:  18
Czas wykonania:  7.100001676008105e-05

Dane z tablicy liniowej: 
Pozycja:  34555
Ilosc operacji:  18
Czas wykonania:  6.160000339150429e-05


Wyszukiwanie interpolacyjne
Dane z tablicy losowej:
Pozycja:  34629
Ilosc operacji:  3
Czas wykonania:  0.00015409995103254914

Dane z tablicy liniowej:
Pozycja:  34555
Ilosc operacji:  2
Czas wykonania:  0.000166199984960258
"""

#Test 3:
"""
Podaj rozmiar tablicy: 10000000
Podaj zakres liczb w tablicy: 10000000
Podaj szukana liczbe: 9876989


Wyszukiwanie liniowe
Dane z tablicy losowej:
Pozycja:  9876900
Ilosc operacji:  9876901
Czas wykonania:  1.4633272999781184

Dane z tablicy liniowej:
Pozycja:  9876988
Ilosc operacji:  9876989
Czas wykonania:  0.35780320002231747


Wyszukiwanie binarne
Dane z tablicy losowej:
Pozycja:  9876901
Ilosc operacji:  21
Czas wykonania:  0.0001246000174432993

Dane z tablicy liniowej:
Pozycja:  9876989
Ilosc operacji:  22
Czas wykonania:  0.00025790004292503


Wyszukiwanie interpolacyjne
Dane z tablicy losowej:
Pozycja:  9876900
Ilosc operacji:  4
Czas wykonania:  0.00012729997979477048

Dane z tablicy liniowej:
Pozycja:  9876989
Ilosc operacji:  1
Czas wykonania:  0.00010349997319281101
"""

#Test 4:
"""
Podaj rozmiar tablicy: 100000000
Podaj zakres liczb w tablicy: 100000000
Podaj szukana liczbe: 9863  


Wyszukiwanie liniowe
Dane z tablicy losowej: 
Pozycja:  9811
Ilosc operacji:  9812
Czas wykonania:  0.0012113999691791832

Dane z tablicy liniowej: 
Pozycja:  9862
Ilosc operacji:  9863
Czas wykonania:  0.0004000000189989805


Wyszukiwanie binarne
Dane z tablicy losowej: 
Pozycja:  9811
Ilosc operacji:  27
Czas wykonania:  7.830001413822174e-05

Dane z tablicy liniowej: 
Pozycja:  9863
Ilosc operacji:  24
Czas wykonania:  0.00014489999739453197


Wyszukiwanie interpolacyjne
Dane z tablicy losowej:
Pozycja:  9811
Ilosc operacji:  4
Czas wykonania:  0.00010810000821948051

Dane z tablicy liniowej:
Pozycja:  9862
Ilosc operacji:  1
Czas wykonania:  0.00013619998935610056
"""

#Test 5:
"""
Podaj rozmiar tablicy: 100000000
Podaj zakres liczb w tablicy: 1000000
Podaj szukana liczbe: 500000


Wyszukiwanie liniowe
Dane z tablicy losowej: 
Pozycja:  50005387
Ilosc operacji:  50005388
Czas wykonania:  8.193531800003257

Dane z tablicy liniowej: 
Pozycja:  499999
Ilosc operacji:  500000
Czas wykonania:  0.03315660002408549


Wyszukiwanie binarne
Dane z tablicy losowej: 
Pozycja:  50005434
Ilosc operacji:  20
Czas wykonania:  7.82000133767724e-05

Dane z tablicy liniowej: 
Pozycja:  499999
Ilosc operacji:  27
Czas wykonania:  4.280003486201167e-05


Wyszukiwanie interpolacyjne
Dane z tablicy losowej: 
Pozycja:  50005399
Ilosc operacji:  3
Czas wykonania:  3.7999998312443495e-05

Dane z tablicy liniowej: 
Pozycja:  499999
Ilosc operacji:  1
Czas wykonania:  3.349996404722333e-05
"""