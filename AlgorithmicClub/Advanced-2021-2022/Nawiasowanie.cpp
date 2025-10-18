//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int M=1<<20;
int tab[2*M]={1000000000};

int  query(int a,int b){
    a=a+M;
    b=b+M;
    int  res=tab[a];
    if(a!=b){
        res=min(res,tab[b]);
    }
    while(a/2!=b/2)
    {
        if(a%2==0){
            res=min(res,tab[a+1]);
        }
        if(b%2==1){
            res=min(res,tab[b-1]);
        }
        a=a/2;
        b=b/2;
    }
    return res;
}

void update(int x,int y){
    x=x+M;
    tab[x]=y;
    while(x!=1){
        x=x/2;
        tab[x]=min(tab[2*x],tab[2*x+1]);
    }

}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,q,a,b;
    string nawiasy;
    cin>>n>>q;
    cin>>nawiasy;
    vector<int> prefiksy(n+1);
    
    for(int i=0;i<n;i++){
        prefiksy[i+1]=prefiksy[i]+((nawiasy[i]=='(')?1:-1);
        update(i,prefiksy[i+1]);
    }
    while(q>0){
        cin>>a>>b;
        if(prefiksy[b]-prefiksy[a-1]==0 && query(a-1,b-1)>=prefiksy[a-1]){
            cout<<"TAK"<<endl;
        }else{
            cout<<"NIE"<<endl;
        }
        q--;
    }

    return 0;
}