//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--){
        int n,flaga=0;
        cin>>n;
        string slowo;
        cin>>slowo;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int indeks1=i,indeks2=j,dlugosc=0;
                while(indeks1<=indeks2){
                    if(slowo[indeks1]==slowo[indeks2]){
                        dlugosc=dlugosc+2;
                        indeks1++;
                        indeks2--;
                    }else{
                        break;
                    }
                }
                if(flaga!=1 && dlugosc>1 && indeks1>indeks2){
                    cout<<"TAK"<<'\n';
                    flaga=1;
                }
            }
        }

        if(flaga==0)cout<<"NIE"<<'\n';
    }
    return 0;
}