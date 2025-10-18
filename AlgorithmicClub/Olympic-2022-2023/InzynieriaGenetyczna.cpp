//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,k;
int akt_epoka=1;

vector<int> geny;
vector<int> epoki;
vector<int> wystapienia;
vector<int> sufiks_ciagu;
vector<int> najmniejszy_gen;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>k;
    
    geny.resize(n);
    epoki.resize(1e6+9,1);
    wystapienia.resize(1e6+9,0);
    sufiks_ciagu.resize(1e6+9);

    for(int i=0;i<n;i++){
        cin>>geny[i];
    }

    sufiks_ciagu[n]=0;
    for(int i=n-1;i>=0;i--){
        if(epoki[geny[i]]!=akt_epoka){
            wystapienia[geny[i]]=0;
            epoki[geny[i]]=akt_epoka;
        }
        if(wystapienia[geny[i]]+1==k){
            sufiks_ciagu[i]=sufiks_ciagu[i+1]+k;
            akt_epoka++;
        }else{
            sufiks_ciagu[i]=sufiks_ciagu[i+1];
            wystapienia[geny[i]]++;
        }
    }

    cout<<sufiks_ciagu[0]<<"\n";
    if(sufiks_ciagu[0]==0)return 0;

    akt_epoka=0;
    int minimum=1e9,indeks=0;

    epoki.clear();
    wystapienia.clear();
    epoki.resize(1e6+9,0);
    wystapienia.resize(1e6+9,0);

    for(int i=0;i<n;i++){   
        if((sufiks_ciagu[i]==sufiks_ciagu[i+1]+k && minimum!=1e9)){
            for(int j=0;j<k;j++){
                cout<<minimum<<" ";
            }
            akt_epoka++;
            minimum=1e9;
            i=indeks+1;

        }
        if(epoki[geny[i]]!=akt_epoka){
            epoki[geny[i]]=akt_epoka;
            wystapienia[geny[i]]=0;
        }
        if(wystapienia[geny[i]]+1==k){
            if(geny[i]<minimum){
                minimum=geny[i];
                indeks=i;
            }
        }else{
            wystapienia[geny[i]]++;
        }
    }

    if(akt_epoka==epoki[minimum]){
        for(int j=0;j<k;j++){
            cout<<minimum<<" ";
        }
    }

    return 0;
}
 