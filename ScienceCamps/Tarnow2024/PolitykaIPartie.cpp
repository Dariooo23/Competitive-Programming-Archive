//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<int> par;
vector<int> tab;
vector<int> ranki;
vector<int> z_kim_sie_klocil;

struct Fau{
    Fau(int n){
        par.resize(n+1);
        ranki.resize(n+1);
        z_kim_sie_klocil.resize(n+1,-1);

        for (int i=1;i<=n;i++){
            par[i]=i;
            ranki[i]=1;
        }
    }

    int find(int a){
        if(par[a]!=a){
            par[a]=find(par[a]);
        }
        return par[a];
    }

    void uni(int a, int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(ranki[a]<ranki[b])
            {
                swap(a,b);
            }

            par[b]=a;
            ranki[a]=ranki[a]+ranki[b];
            ranki[b]=ranki[a];

            if(z_kim_sie_klocil[a]!=-1 && z_kim_sie_klocil[b]!=-1){
                uni(z_kim_sie_klocil[a],z_kim_sie_klocil[b]);

                z_kim_sie_klocil[a]=find(z_kim_sie_klocil[a]);
                z_kim_sie_klocil[b]=find(z_kim_sie_klocil[b]);
                return;
            }
            if(z_kim_sie_klocil[a]!=-1){
                z_kim_sie_klocil[b]=z_kim_sie_klocil[a];
            }
            if(z_kim_sie_klocil[b]!=-1){
                z_kim_sie_klocil[a]=z_kim_sie_klocil[b];
            }
        }
        return; 
    }
};

int main(){
    //std::ios_base::sync_with_stdio(0);
    //cout.tie(0);
    //cin.tie(0);

    int n,m;
    cin>>n>>m;

    Fau fau(n);

    for(int i=1;i<=m;i++){
        int typ,a,b;
        cin>>typ;

        if(typ==1){
            cin>>a>>b;
            a=fau.find(a);
            b=fau.find(b);
            if(z_kim_sie_klocil[a]!=-1){
                if(b==fau.find(z_kim_sie_klocil[a])){
                    cout<<-1<<endl;
                    continue;
                }
            }
            if(z_kim_sie_klocil[b]!=-1){
                if(a==fau.find(z_kim_sie_klocil[b])){
                    cout<<-1<<endl;
                    continue;
                }
            }
            fau.uni(a,b);
        }
        if(typ==2){
            cin>>a>>b;
            a=fau.find(a);
            b=fau.find(b);

            if(a==b){
                cout<<-1<<endl;
            }else{
                if(z_kim_sie_klocil[b]!=-1){
                    fau.uni(a,z_kim_sie_klocil[b]);
                }
                if(z_kim_sie_klocil[a]!=-1){
                    fau.uni(b,z_kim_sie_klocil[a]);
                }

                z_kim_sie_klocil[a]=b;
                z_kim_sie_klocil[b]=a;
            }
        }
        if(typ==3){
            cin>>a>>b;
            a=fau.find(a);
            b=fau.find(b);

            if(a==b){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
        if(typ==4){
            cin>>a>>b;
            a=fau.find(a);
            b=fau.find(b);
            if(z_kim_sie_klocil[a]!=-1){
                if(b==fau.find(z_kim_sie_klocil[a])){
                    cout<<1<<endl;
                    continue;
                }
            }
            if(z_kim_sie_klocil[b]!=-1){
                if(a==fau.find(z_kim_sie_klocil[b])){
                    cout<<1<<endl;
                    continue;
                }
            }

            cout<<0<<endl;
        }
    }
    return 0;
}