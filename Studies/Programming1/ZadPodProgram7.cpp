// Karol Dziekan
#include <iostream>

using namespace std;

void iloczyn_liczb(int ile_znakow1, char liczba1[], int ile_znakow2, char liczba2[], int &ile_znakow3, char liczba3[])
{
    if (liczba1[0] == '0' || liczba1[0] == '0')
    {
        ile_znakow3 = 1;
        liczba3[0] = '0';
        return;
    }

    ile_znakow3 = ile_znakow1 + ile_znakow2 + 1;
    int przesuniecie = 2;
    // Dodanie znaku + w przypadku dodatnich
    if (liczba1[0] != '-')
    {
        for (int i = ile_znakow1; i >= 1; i--)
        {
            liczba1[i] = liczba1[i - 1];
        }
        liczba1[0] = '+';
        ile_znakow1++;
    }
    else
    {
        przesuniecie++;
    }

    if (liczba2[0] != '-')
    {
        for (int i = ile_znakow2; i >= 1; i--)
        {
            liczba2[i] = liczba2[i - 1];
        }
        liczba2[0] = '+';
        ile_znakow2++;
    }
    else
    {
        przesuniecie++;
    }

    int indeks1 = 0;
    int indeks2 = 0;
    for (int i = ile_znakow1 - 1; i >= 1; i--)
    {
        int przeniesienie = 0;
        int cyfra1 = liczba1[i] - '0';

        indeks2 = 0;
        for (int j = ile_znakow2 - 1; j >= 1; j--)
        {
            int cyfra2 = liczba2[j] - '0';
            int suma = cyfra1 * cyfra2 + liczba3[ile_znakow3 - (indeks1 + indeks2) - przesuniecie] + przeniesienie;

            przeniesienie = suma / 10;
            liczba3[ile_znakow3 - (indeks1 + indeks2) - przesuniecie] = suma % 10;

            indeks2++;
        }

        if (przeniesienie > 0)
        {
            liczba3[ile_znakow3 - (indeks1 + indeks2) - przesuniecie] = liczba3[ile_znakow3 - (indeks1 + indeks2) - przesuniecie] + przeniesienie;
        }

        indeks1++;
    }

    if (liczba1[0] == liczba2[0])
    {
        liczba3[0] = '+';
    }
    else
    {
        liczba3[0] = '-';
    }

    for (int i = 1; i <= ile_znakow3; i++)
    {
        liczba3[i] += '0';
    }

    while (liczba3[ile_znakow3] == '0')
    {
        liczba3[ile_znakow3] = 0;
        ile_znakow3--;
    }

    if (liczba3[0] == '+')
    {
        for (int i = 0; i < ile_znakow3; i++)
        {
            liczba3[i] = liczba3[i + 1];
        }
        liczba3[ile_znakow3] = 0;
        ile_znakow3--;
    }
    return;
}

int main()
{
    int ile_znakow1 = 0;

    cin >> ile_znakow1;

    char liczba1[ile_znakow1 + 1] = {};

    cin >> liczba1;

    int ile_znakow2 = 0;

    cin >> ile_znakow2;

    char liczba2[ile_znakow2 + 1] = {};

    cin >> liczba2;

    int ile_znakow3 = 0;

    char liczba3[ile_znakow1 + ile_znakow2 + 1] = {};

    iloczyn_liczb(ile_znakow1, liczba1, ile_znakow2, liczba2, ile_znakow3, liczba3);

    cout << ile_znakow3 << " " << liczba3;
    return 0;
}