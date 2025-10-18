#include <bits/stdc++.h>

using namespace std;
vector<int> wynik;

void podzial(int pos,int suma,int liczba)
{
    if (suma==liczba)
    {
            for(int i=0;i<wynik.size();i++)
        {
            cout<<wynik[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(suma+pos>liczba)
    {
        return;
    }
        wynik.push_back(pos);
        podzial(pos,suma+pos,liczba);
        wynik.pop_back();
        podzial(pos+1,suma,liczba);
}

int main()
{
    int liczba,suma=0,pos=1;
    cin>>liczba;
    podzial(pos,suma,liczba);
    return 0;
}