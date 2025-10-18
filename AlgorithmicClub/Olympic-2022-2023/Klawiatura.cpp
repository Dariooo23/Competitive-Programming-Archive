//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> skoki;
vector<int> pozycje;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string wejscie;
    cin>>wejscie;


    skoki.resize(wejscie.size()+1,vector<int> (54,wejscie.size()+2));
    pozycje.resize(54,wejscie.size()+2);
    for(int i=0;i<wejscie.size();i++){
        if(i%2==1){
            if(wejscie[i]>='A' && wejscie[i]<='Z'){
                wejscie[i]=wejscie[i]+32;
            }else{
                wejscie[i]=wejscie[i]-32;
            }
        }
    }

    for(int i=wejscie.size();i>=0;i--){
        skoki[i]=pozycje;
        if(i!=0){
            if(wejscie[i-1]>='a' && wejscie[i-1]<='z'){
                pozycje[wejscie[i-1]-'a']=i;
            }else{
                pozycje[wejscie[i-1]-'A'+26]=i;
            }
        }
    }


    int q;
    cin>>q;
    while(q--){
        string zapytanie;
        cin>>zapytanie;
        for(int i=0;i<zapytanie.size();i++){
            if(i%2==1){
                if(zapytanie[i]>='A' && zapytanie[i]<='Z'){
                    zapytanie[i]=zapytanie[i]+32;
                }else{
                    zapytanie[i]=zapytanie[i]-32;
                }
            }
        }

        int indeks;
        if(zapytanie[0]>='a' && zapytanie[0]<='z'){
            indeks=zapytanie[0]-'a';
        }else{
            indeks=zapytanie[0]-'A'+26;
        }

        int wskaznik=skoki[0][indeks],flaga=0;
        if(wskaznik==wejscie.size()+2){
            flaga=1;
        }else{
            if(wejscie[wskaznik-1]!=zapytanie[0]){
            flaga=1;
            }else{
                for(int i=1;i<zapytanie.size();i++){
                    if(zapytanie[i]>='a' && zapytanie[i]<='z'){
                        indeks=zapytanie[i]-'a';
                    }else{
                        indeks=zapytanie[i]-'A'+26;
                    }
    
                    wskaznik=skoki[wskaznik][indeks];
    
                    if(wskaznik==wejscie.size()+2){
                        flaga=1;
                        break;
                    }
                    if(wejscie[wskaznik-1]!=zapytanie[i]){
                        flaga=1;
                        break;
                    }
                }
            }
        }
        if(flaga){
            cout<<"NIE"<<endl;
        }else{
            cout<<"TAK"<<endl;
        }
    }
    return 0;
}