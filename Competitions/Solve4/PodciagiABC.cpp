//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> indeksa;
vector<int> indeksb;
vector<int> indeksc;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string slowo;
    cin>>slowo;

    int indeks1=0,indeks2=0,wynik=0;
    for(int i=0;i<slowo.size();i++){
        if(slowo[i]=='A'){
            indeksa.push_back(i);
        }
        if(slowo[i]=='B'){
            indeksb.push_back(i);
        }
        if(slowo[i]=='C'){
            indeksc.push_back(i);
        }
    }

    for(int i=0;i<indeksa.size();i++){
        while(indeks1<indeksb.size() && indeksb[indeks1]<indeksa[i]){
            indeks1++;
        }
        if(indeks1==indeksb.size()){
            break;
        }
        
        if(indeksb[indeks1]>indeksa[i]){
            while(indeks2<indeksc.size() && indeksc[indeks2]<indeksb[indeks1]){
                indeks2++;
            }
            if(indeks2==indeksc.size()){
                break;
            }
            if(indeksc[indeks2]>indeksb[indeks1]){
                wynik++;
                indeks1++;
                indeks2++;
            }
        }
    }

    cout<<wynik;
    return 0;
}