//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int par[200010];
int ranki[200010];
int wyniki[200010];
int malpki[200010][2];
int ruchy[400010][2];

    int find(int a){
        if (par[a]!=a){
            int rodzic=par[a];
            par[a]=find(par[a]);
            if(wyniki[a]==-2){
                wyniki[a]=wyniki[rodzic];
            }
        }
        return par[a];
    }
    void uni(int x,int y)
    {
        x=find(x);
        y=find(y);

        if(x==y){
            return;
        }

        if(ranki[x]>ranki[y]) {
            par[y]=x;
        }else{
            par[x]=y;
        }

        if(ranki[x]==ranki[y]){
            ranki[x]++;
        }
        return;
    }

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int malpy,czas;
    cin>>malpy>>czas;

    for (int i=0; i<=malpy;i++){
        wyniki[i]=-2;
        ranki[i]=0;
        par[i]=i;
    }

    for(int i=1;i<=malpy;i++){
        cin>>malpki[i][0]>>malpki[i][1];
    }
    for(int i=1;i<=czas;i++){
        int malpa,reka;
        cin>>malpa>>reka;
        reka--;

        ruchy[i][0]=malpki[malpa][reka];
        ruchy[i][1]=malpa;
        malpki[malpa][reka]=-1;
    }

    for(int i=1;i<=malpy;i++){
        for(int j=0;j<=1;j++){
            if(malpki[i][j]!=-1){
                uni(i,malpki[i][j]);
            }
        }
    }

    wyniki[find(1)]=-1;
    for(int i=czas;i>=1;i--){
        int lewo=find(ruchy[i][0]),prawo=find(ruchy[i][1]);
        int rodzic=find(1);
        if(lewo==rodzic && lewo!=prawo){
            wyniki[prawo]=i-1;
        }else{
            if(prawo==rodzic && lewo!=prawo){
                wyniki[lewo]=i-1;
            }
        }
        uni(lewo,prawo);
    }

    for(int i=1;i<=malpy;i++){
        find(i);
        cout<<wyniki[i]<<endl;
    }

    return 0;
}