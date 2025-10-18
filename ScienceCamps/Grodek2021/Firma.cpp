//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> szefowie;
long long int sumy[200001];
long long int sumypref[200001];
vector<long long int> graf[200001];
long long int maximum=1e18;


void DFS(long long int punkt,long long int dod){
    long long int maksimum=0;
    long long int sum=0;
    if(graf[punkt].empty()){
        sumy[punkt]=dod;
        sumypref[punkt]=dod;
        return;
    }
    for(int v:graf[punkt] ){
          DFS(v,dod);
            sum=sum+sumypref[v];
            if(sum>maximum) sum=maximum+7;
            if(maksimum<sumy[v]) maksimum=sumy[v];

    }
    sumy[punkt]=((maksimum*3)+1)/2;
    if(sumy[punkt]>maximum)sumy[punkt]=maximum+7;


    sumypref[punkt]=sumy[punkt]+sum;
    if(sumypref[punkt]>maximum) sumypref[punkt]=maximum+7;
}


long long int dziala(long long int k, int zmienna){
    long long int sumak=0;
    for(int szef : szefowie){
        DFS(szef,k);
        sumak=sumak+sumypref[szef];
        if(sumak>maximum){
            return maximum+7;
        }
    }
    return sumak;
}


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int osoby,kasa,zmienna=0;
    cin>>osoby>>kasa;

    for(int i=1;i<=osoby;i++){
        int a;
        cin>>a;
        if(a==0){
            szefowie.push_back(i);
        }else{
            graf[a].push_back(i);
        }
    }

    long long int L=0,R=1e18,wyn=0;
    while(L<R){
        long long int mid=(L+R+1)/2;
        wyn=dziala(mid,zmienna);
        if(wyn==kasa){
            if(mid==0){
                cout<<"NIE";
            }else{
              cout<<mid;  
            }
           
           exit(0);
        }
        if(wyn>kasa){
            R=mid-1;
        }else{
            L=mid;
        }
    }
    if(dziala(L,zmienna)>kasa || L==0){
        cout<<"NIE";
    }else{
          cout<<L;
    }

    return 0;
}