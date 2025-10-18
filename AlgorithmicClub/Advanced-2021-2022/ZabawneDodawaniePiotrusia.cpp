//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

string dodaj(string liczba1,string liczba2)
{
    string wynik="";
    if(liczba2.size()>liczba1.size())
    {
        swap(liczba1,liczba2);
    }


    int rozmiar=0,liczba=0;
    while(rozmiar<liczba2.size())
    {
        liczba = liczba + (int) (liczba1[liczba1.size()-1-rozmiar] - '0' + liczba2[liczba2.size()-1-rozmiar] - '0');
        liczba1[liczba1.size()-1-rozmiar]=(char) (liczba%10 + '0');
        liczba=liczba/10;
        rozmiar++;
    }
    while(rozmiar<liczba1.size())
    {
        liczba = liczba + (int) (liczba1[liczba1.size()-1-rozmiar] - '0');
        liczba1[liczba1.size()-1-rozmiar]=(char) (liczba%10 + '0');
        liczba=liczba/10;
        rozmiar++;
    }
    if(liczba!=0)
    {
        wynik=wynik+(char)(liczba+'0');
    }
    wynik=wynik+liczba1;
    return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int q;
    cin>>q;

    while(q--)
    {
        int ile=0;
        string liczba1,liczba2;

        cin>>liczba1;
        liczba2=liczba1;
        reverse(liczba2.begin(),liczba2.end());

        while(liczba1!=liczba2)
        {
            liczba1=dodaj(liczba1,liczba2);
            liczba2=liczba1;
            reverse(liczba2.begin(),liczba2.end());
            ile++;
        }
        cout<<liczba1<<" "<<ile<<endl;
    }
    return 0;
}