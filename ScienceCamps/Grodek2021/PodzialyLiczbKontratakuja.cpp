#include <bits/stdc++.h>

using namespace std;
vector<int> wynik;

void podzial(int pos,int suma,int liczba,int k)
{

      if (suma==liczba && wynik.size()==k)
    {
            for(int i=0;i<wynik.size();i++)
        {
            cout<<wynik[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(suma+pos>liczba || wynik.size()>k)
    {
        return;
    }
    wynik.push_back(pos);
        podzial(pos,suma+pos,liczba,k);
        wynik.pop_back();
        podzial(pos+1,suma,liczba,k);




}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int liczba,suma=0,pos=1,k;
    cin>>liczba>>k;
    podzial(pos,suma,liczba,k);
   
    return 0;
}