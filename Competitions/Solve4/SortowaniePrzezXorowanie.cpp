//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> tab1;
vector<int> tab2;
vector<int> pref;
vector<int> suf;

vector<int> prefsum;
vector<int> sufsum;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,k,wynik=1e9+9;
    cin>>n>>k;

    int potega=(1<<k)-1;

    suf.resize(n+2);
    tab1.resize(n+2);
    tab2.resize(n+2);
    pref.resize(n+2);

    sufsum.resize(n+2);
    prefsum.resize(n+2);

    for(int i=1;i<=n;i++){
        cin>>tab1[i];
        tab2[i]=(potega^tab1[i]);
    }
    /*for(int i=1;i<=n;i++){
        cout<<tab2[i]<<" ";
    }cout<<endl;*/


    //Obliczanie jak daleko moze zajsc ciag od lewej
    tab1[0]=0;
    tab2[0]=0;
    pref[0]=0;
    for(int i=1;i<=n;i++){
        if(pref[i-1]==-1){
            pref[i]=-1;
            continue;
        }

        int minimum=min(tab1[i],tab2[i]);
        if(minimum>=min(tab1[i-1],tab2[i-1])){
            if(minimum==tab1[i]){
                pref[i]=0;
            }else{
                pref[i]=1;
            }
        }else{
            pref[i]=-1;
        }
    }
    if(pref[n]==-1){
        pref[n+1]=-1;
    }else{
        pref[n+1]=0;
    }
    /*for(int i=0;i<=n+1;i++){
        cout<<pref[i]<<" ";
    }cout<<endl;*/
    //Obliczanie jak daleko moze zajsc ciag od prawej
    suf[n+1]=0;
    tab1[n+1]=1e9+9;
    tab2[n+1]=1e9+9;
    for(int i=n;i>=1;i--){
        if(suf[i+1]==-1){
            suf[i]=-1;
            continue;
        }

        int maksimum=max(tab1[i],tab2[i]);
        if(maksimum<=max(tab1[i+1],tab2[i+1])){
            if(maksimum==tab1[i]){
                suf[i]=0;
            }else{
                suf[i]=1;
            }
        }else{
            suf[i]=-1;
        }
    }
    if(suf[1]==-1){
        suf[0]=-1;
    }else{
        suf[0]=0;
    }
    /*for(int i=0;i<=n+1;i++){
        cout<<suf[i]<<" ";
    }cout<<endl;*/


    //Obliczanie ile jest spojnych ciagow zamian od lewej
    prefsum[0]=0;
    for(int i=1;i<=n;i++){
        if(pref[i]!=pref[i-1]){
            prefsum[i]=prefsum[i-1]+1;
        }else{
            prefsum[i]=prefsum[i-1];
        }
    }
    /*for(int i=0;i<=n+1;i++){
        cout<<prefsum[i]<<" ";
    }cout<<endl;*/
    //Obliczanie ile jest spojnych ciagow zamian od prawej
    sufsum[n+1]=0;
    for(int i=n;i>=1;i--){
        if(suf[i]!=suf[i+1]){
            sufsum[i]=sufsum[i+1]+1;
        }else{
            sufsum[i]=sufsum[i+1];
        }
    }
    /*for(int i=0;i<=n+1;i++){
        cout<<sufsum[i]<<" ";
    }cout<<endl;*/


    //Obliczanie wyniku jako suma ciagu z lewej i prawej
    for(int i=0;i<=n;i++){
        if(pref[i]!=-1 && suf[i+1]!=-1){
            int flaga=0;
            if(pref[i]!=suf[i+1]){
                flaga=1;
            }
            wynik=min(wynik,prefsum[i]+sufsum[i+1]+flaga);
        }
    }
    if(wynik==1e9+9){
        cout<<-1;
    }else{
        cout<<wynik/2;
    }
    return 0;
}