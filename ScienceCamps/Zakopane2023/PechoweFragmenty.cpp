//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int  n,k;
long long int  podstawa=1<<20;
vector<long long int > drzewo(podstawa*2+1);
vector<long long int > suma(podstawa*2+1);
map<long long int ,long long int > pos;
vector<long long int > nxt;
vector<long long int > tab;

void popraw(int rodzic, int y1, int y2)
{
    if(drzewo[rodzic]>0)
    {
        suma[rodzic]=y2-y1+1;
    }
    else
    {
        suma[rodzic]=0;
        if(y1<y2)
        {
            suma[rodzic]=suma[rodzic*2]+suma[rodzic*2+1];
        }
    }
}

void zmien(int rodzic,int y1,int y2,int lewo,int prawo,int znak)
{
    if(y1<=lewo && y2>=prawo)
    {
        drzewo[rodzic]=drzewo[rodzic]+znak;
    }
    else
    {
        int mid=(lewo+prawo)/2;
        if(y1<=mid)
        {
            zmien(rodzic*2,y1,y2,lewo,mid,znak);
        }
        if(y2>mid)
        {
            zmien(rodzic*2+1,y1,y2,mid+1,prawo,znak);
        }
    }
    popraw(rodzic,lewo,prawo);
}

int  main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>k;

    nxt.resize(n);
    tab.resize(n);

    for(long long int  i=0;i<n;i++){
        cin>>tab[i];
    }

    for(long long int  i=n-1;i>=0;i--){
        if(pos.find(tab[i])!=pos.end()){
            nxt[i]=pos[tab[i]];
        }else{
            nxt[i]=n;
        }

        pos[tab[i]]=i;
    }

    for(auto &v:pos){
        long long int  indeks=v.second;
        if(v.first==k)continue;
        for(long long int  i=0;i<k-1 && indeks<n;i++){
            indeks=nxt[indeks];
        }

        v.second=indeks;
        if(indeks<n){
            //cout<<indeks<<" "<<nxt[indeks]-1<<" +"<<endl;
            zmien(1,indeks,nxt[indeks]-1,0,podstawa,1);
        }
    }

    long long int  kindeks=n;
    for(long long int  i=0;i<n;i++){
        if(tab[i]==k){
            kindeks=i;
            break;
        }
    }

    if(kindeks<n){
        //cout<<kindeks<<" "<<n-1<<" +"<<endl;
        zmien(1,kindeks,n-1,0,podstawa,1);
    }

    long long int  wynik=suma[1];
    //cout<<"korzen "<<suma[1]<<endl;

    for(long long int  i=0;i<n;i++){
        //cout<<i<<":"<<endl;
        if(tab[i]==k){
            if(kindeks<n)zmien(1,kindeks,n-1,0,podstawa,-1);

            if(kindeks<n){
                kindeks=nxt[kindeks];
            }

            if(kindeks<n)zmien(1,kindeks,n-1,0,podstawa,1);
        }else{
            long long int  indeks=pos[tab[i]];
            if(indeks<n){
                //cout<<indeks<<" "<<nxt[indeks]-1<<" -"<<endl;
                zmien(1,indeks,nxt[indeks]-1,0,podstawa,-1);
            }

            if(indeks<n){
                pos[tab[i]]=nxt[pos[tab[i]]];
                indeks=pos[tab[i]];
            }

            
            if(indeks<n){
                //cout<<indeks<<" "<<nxt[indeks]-1<<" +"<<endl;
                zmien(1,indeks,nxt[indeks]-1,0,podstawa,1);
            }
        }
        //cout<<endl;
        wynik=wynik+suma[1];
        //cout<<"korzen "<<suma[1]<<endl;
    }

    cout<<wynik;

    return 0;
}