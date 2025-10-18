//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const unsigned long long int podstawa=29;
const unsigned long long int podstawa2=37;
const unsigned long long int modulo=1e9+696969;
unsigned long long int pow29[1000009];
unsigned long long int pow37[1000009];
map<pair<int,int>, int> wzorce;
vector<unsigned long long int> HasheWzorcow(20);
vector<unsigned long long int> HasheWzorcow2(20);
vector<unsigned long long int> sHash(1000009);
vector<unsigned long long int> sHash2(1000009);
vector<string> wstepnewzorce(20);


unsigned long long int hashowanie(string s) {
    unsigned long long int hash=0;

    for(char I : s)
    {
        hash=hash*podstawa;
        hash=hash+(I-'a'+1);
        hash=hash%modulo;
    }

    return hash;
}
unsigned long long int hashowanie2(string s) {
    unsigned long long int hash=0;

    for(char I : s)
    {
        hash=hash*podstawa2;
        hash=hash+(I-'a'+1);
        hash=hash%modulo;
    }

    return hash;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pow29[0]=1;
    for(int i=1;i<=100009;i++)
    {
        pow29[i]=(pow29[i-1]*podstawa)%modulo;
    }
    pow37[0]=1;
    for(int i=1;i<=100009;i++)
    {
        pow37[i]=(pow37[i-1]*podstawa2)%modulo;
    }


    string s;
    int n,rozmiar=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        wstepnewzorce[i]=a;
        HasheWzorcow[i]=hashowanie(a);
        HasheWzorcow2[i]=hashowanie2(a);
        rozmiar=rozmiar+a.size();
    }
    /*cout<<"HASHE WZORCOW"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<HasheWzorcow[i]<<" ";
    }*/


    cin>>s;
    if(s.size()==0 || n==0 || rozmiar>s.size())
    {
        cout<<0;
        exit(0);
    }
    sHash[0]=hashowanie(s.substr(0,rozmiar));   
    for(unsigned int i = 1;i <= s.length()-rozmiar;++i) 
    {
        sHash[i]=(sHash[i-1]-(((s[i-1]-'a'+1)*pow29[rozmiar-1])%modulo)+modulo)%modulo;
        sHash[i]=sHash[i]*podstawa;
        sHash[i]=sHash[i]+(s[i+rozmiar-1]-'a'+1);
        sHash[i]=sHash[i]%modulo;;
    }


    sHash2[0]=hashowanie2(s.substr(0,rozmiar));   
    for(unsigned int i = 1;i <= s.length()-rozmiar;++i) 
    {
        sHash2[i]=(sHash2[i-1]-(((s[i-1]-'a'+1)*pow37[rozmiar-1])%modulo)+modulo)%modulo;
        sHash2[i]=sHash2[i]*podstawa2;
        sHash2[i]=sHash2[i]+(s[i+rozmiar-1]-'a'+1);
        sHash2[i]=sHash2[i]%modulo;;
    }
    /*cout<<"HASH SLOWA"<<endl;
    for(int i=0;i<=s.length()-rozmiar;i++)
    {
        cout<<i<<" "<<sHash[i]<<endl;
    }*/


    vector<int> per(n);
    for(int i=0;i<n;i++)
    {
        per[i]=i;
    }


    do {
        unsigned long long int Hash=0,Hash2=0;
        for(int i=0;i<n;i++)
        {
            Hash=(Hash*pow29[wstepnewzorce[per[i]].size()])%modulo;
            Hash=(Hash+HasheWzorcow[per[i]])%modulo;
            Hash2=(Hash2*pow37[wstepnewzorce[per[i]].size()])%modulo;
            Hash2=(Hash2+HasheWzorcow2[per[i]])%modulo;
        }
        if(wzorce.find({Hash,Hash2})==wzorce.end())
        {
            wzorce[{Hash,Hash2}]=1;
        }
        else
        {
            wzorce[{Hash,Hash2}]=wzorce[{Hash,Hash2}]+1;
        }
    } while(next_permutation(per.begin(), per.end()));


    unsigned long long int wynik=0;
    for(int i=0;i<=s.length()-rozmiar;i++)
    {
        if(wzorce.find({sHash[i],sHash2[i]})!=wzorce.end())
        {
            wynik=wynik+wzorce[{sHash[i],sHash2[i]}];
        }
    }
    cout<<wynik;
    return 0;
}