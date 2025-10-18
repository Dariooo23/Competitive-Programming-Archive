//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<long long int> stworz_ciag(long long int n,long long int a){
    long long int potega=1,suma=1;
    vector<long long int> ciag;
    ciag.push_back(a);

    while(suma<a){
        potega=potega*n;
        suma=suma+potega;
    }

    suma=suma-potega;
    potega=potega/n;
    a=a-suma;
    
    while(potega>=1){
        suma=suma-potega;
        potega=potega/n;
        a=(a-1)/n+1;
        ciag.push_back(a+suma);
    }
    
    reverse(ciag.begin(),ciag.end());
    return ciag;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int q;
    cin>>q;
    while(q--){
        long long int n,a,b;
        cin>>n>>a>>b;

        if(n==1){
            cout<<min(a,b)<<endl;
            continue;
        }

        vector<long long int> ciaga,ciagb;
        ciaga=stworz_ciag(n,a);
        ciagb=stworz_ciag(n,b);

        bool roznica=0;
        int indeks=0;

        while(indeks<ciaga.size() && indeks<ciagb.size()){
            if(ciaga[indeks]==ciagb[indeks]){
                indeks++;
            }else{
                roznica=1;
                indeks--;
                break;
            }
        }
        if(roznica==0){
            cout<<min(a,b)<<endl;
        }else{
            cout<<ciaga[indeks]<<endl;
        }
    }
    return 0;
}