//Karol Dziekan
#include<bits/stdc++.h>

using namespace std;

vector<int> pozycje1;
vector<int> pozycje2;
vector<bool> usuniete;
vector<bool> pokrycie;
vector<vector<int>> graf1;

int akt_punkt=1;
int backtrack(const int pozycja1,const int pozycja2,const int maks_usun){
    if(maks_usun<0)return -1;
    if(pozycja1>=akt_punkt)return 0;

    if(!usuniete[pozycja1]){
        vector<bool> usuniete_kopia1;
        for(int i=pozycja2;i<graf1[pozycje1[pozycja1]].size();i++){
            if(usuniete[pozycje2[graf1[pozycje1[pozycja1]][i]]])continue;

            usuniete_kopia1=usuniete;
            usuniete[pozycja1]=1;

            int wynik1=backtrack(pozycja1+1,0,maks_usun-1);

            swap(usuniete_kopia1,usuniete);
            usuniete[pozycje2[graf1[pozycje1[pozycja1]][i]]]=1;

            int wynik2=backtrack(pozycja1,i+1,maks_usun-1);

            if(wynik1>wynik2){
                wynik2=wynik1;
                usuniete=usuniete_kopia1;
            }
            return wynik2;
        }
    }

    int wynik=backtrack(pozycja1+1,0,maks_usun);
    if(wynik>=0 && !usuniete[pozycja1])wynik++;
    return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,k,m;
    cin>>n>>k>>m;

    graf1.resize(n+1);
    pozycje2.resize(n+1);
    pozycje1.resize(210);
    usuniete.resize(210);
    pokrycie.resize(n+1,0);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        graf1[a].push_back(b);
        graf1[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(graf1[i].begin(), graf1[i].end());
        graf1[i].erase(unique(graf1[i].begin(), graf1[i].end()),graf1[i].end());
    }

    int maks_usun=n-k;
    int usuniete_ilosc=0;
    for(int i=1;i<=n;i++){
        if(graf1[i].size()>maks_usun){
            usuniete_ilosc++;
            pokrycie[i]=1;
        }
    }

    for(int i=1;i<=n;i++){
        if(pokrycie[i])continue;
        for(int j=0; j<graf1[i].size();j++){
            if(pokrycie[graf1[i][j]]){
                if(j+1<graf1[i].size())swap(graf1[i][j],graf1[i].back());
                graf1[i].pop_back();
                --j;
            }
        }

        if(graf1[i].size()>0){
            pozycje1[akt_punkt]=i;
            pozycje2[i]=akt_punkt;
            akt_punkt++;

            if(akt_punkt>=maks_usun*maks_usun*2){
                cout<<"NIE";
                return 0;
            }
        }
    }

    maks_usun=maks_usun-usuniete_ilosc;

    backtrack(1,0,maks_usun);
    for(int i=1;i<akt_punkt;i++){
        if(usuniete[i])pokrycie[pozycje1[i]]=1;
    }

    int wynik=n;
    for(int i=1;i<=n;i++){
        if(pokrycie[i])wynik--;
    }
    if(wynik<k){
        cout<<"NIE";
        return 0;
    }

    cout<<wynik<<endl;
    for(int i=1;i<=n;i++){
        if(pokrycie[i])continue;
        cout<<i<<" ";
    }
    return 0;
}
 