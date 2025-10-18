//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> licznik(500,0);
vector<int> liczba;

bool cmp(const int &a,const int &b){
    return a>b;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int rozmiar;
    cin>>rozmiar;
    
    string slowo;
    cin>>slowo;

    for(int i=0;i<slowo.size();i++){
        licznik[slowo[i]]++;
    }
    while(licznik['j']>=1 && licznik['e']>=2 && licznik['d']>=1 && licznik['n']>=1){
        licznik['j']=licznik['j']-1;
        licznik['e']=licznik['e']-1;
        licznik['d']=licznik['d']-1;
        licznik['e']=licznik['e']-1;
        licznik['n']=licznik['n']-1;
        liczba.push_back(1);
    }
    while(licznik['d']>=1 && licznik['w']>=1 && licznik['a']>=1){
        licznik['d']=licznik['d']-1;
        licznik['w']=licznik['w']-1;
        licznik['a']=licznik['a']-1;
        liczba.push_back(2);
    }
    while(licznik['d']>=1 && licznik['z']>=1 && licznik['i']>=2 && licznik['e']>=2 && licznik['w']>=1 && licznik['c']>=1){
        licznik['d']=licznik['d']-1;
        licznik['z']=licznik['z']-1;
        licznik['i']=licznik['i']-1;
        licznik['e']=licznik['e']-1;
        licznik['w']=licznik['w']-1;
        licznik['i']=licznik['i']-1;
        licznik['e']=licznik['e']-1;
        licznik['c']=licznik['c']-1;
        liczba.push_back(9);
    }
    while(licznik['s']>=1 && licznik['i']>=1 && licznik['e']>=2 && licznik['d']>=1 && licznik['m']>=1){
        licznik['s']=licznik['s']-1;
        licznik['i']=licznik['i']-1;
        licznik['e']=licznik['e']-1;
        licznik['d']=licznik['d']-1;
        licznik['e']=licznik['e']-1;
        licznik['m']=licznik['m']-1;
        liczba.push_back(7);
    }
    while(licznik['p']>=1 && licznik['i']>=1 && licznik['e']>=1 && licznik['c']>=1){
        licznik['p']=licznik['p']-1;
        licznik['i']=licznik['i']-1;
        licznik['e']=licznik['e']-1;
        licznik['c']=licznik['c']-1;
        liczba.push_back(5);
    }
    while(licznik['o']>=1 && licznik['s']>=1 && licznik['i']>=1 && licznik['e']>=1 && licznik['m']>=1){
        licznik['o']=licznik['o']-1;
        licznik['s']=licznik['s']-1;
        licznik['i']=licznik['i']-1;
        licznik['e']=licznik['e']-1;
        licznik['m']=licznik['m']-1;
        liczba.push_back(8);
    }
    while(licznik['z']>=1 && licznik['e']>=1 && licznik['r']>=1 && licznik['o']>=1){
        licznik['z']=licznik['z']-1;
        licznik['e']=licznik['e']-1;
        licznik['r']=licznik['r']-1;
        licznik['o']=licznik['o']-1;
        liczba.push_back(0);
    }
    while(licznik['s']>=2 && licznik['z']>=1 && licznik['e']>=1 && licznik['c']>=1){
        licznik['s']=licznik['s']-1;
        licznik['z']=licznik['z']-1;
        licznik['e']=licznik['e']-1;
        licznik['s']=licznik['s']-1;
        licznik['c']=licznik['c']-1;
        liczba.push_back(6);
    }
    while(licznik['c']>=1 && licznik['z']>=1 && licznik['t']>=1 && licznik['e']>=1 && licznik['r']>=1 && licznik['y']>=1){
        licznik['c']=licznik['c']-1;
        licznik['z']=licznik['z']-1;
        licznik['t']=licznik['t']-1;
        licznik['e']=licznik['e']-1;
        licznik['r']=licznik['r']-1;
        licznik['y']=licznik['y']-1;
        liczba.push_back(4);
    }
    while(licznik['t']>=1 && licznik['r']>=1 && licznik['z']>=1 && licznik['y']>=1){
        licznik['t']=licznik['t']-1;
        licznik['r']=licznik['r']-1;
        licznik['z']=licznik['z']-1;
        licznik['y']=licznik['y']-1;
        liczba.push_back(3);
    }

    sort(liczba.begin(),liczba.end(),cmp);
    for(int i=0;i<liczba.size();i++){
        cout<<liczba[i];
    }
    return 0;
}