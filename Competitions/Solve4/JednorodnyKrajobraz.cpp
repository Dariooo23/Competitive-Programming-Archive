//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> wejscie(n+2);
    wejscie[n+1]=0;
    wejscie[0]=0;

    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
    }

    long double wynik=0;
    for(int i=1;i<=n;i++){
        int maksimum=wejscie[i],minimum=wejscie[i],dlugosc=1;
        int indeksl=i-1,indeksp=i+1;
        while(indeksl!=0 || indeksp!=n+1){
            wynik=max(wynik,(long double)((long double)minimum/(long double)maksimum)*(long double)dlugosc);
            int flagal=0,flagap=0;
            if(wejscie[indeksl]<=maksimum){
                flagal=1;
            }
            if(wejscie[indeksp]<=maksimum){
                flagap=1;
            }
            if(flagal==0 && flagap==0){
                break;
            }else{
                if(flagal==1 && flagap==1){
                    if(wejscie[indeksl]>wejscie[indeksp]){
                        minimum=min(minimum,wejscie[indeksl]);
                        indeksl--;
                        dlugosc++;
                    }else{
                        minimum=min(minimum,wejscie[indeksp]);
                        indeksp++;
                        dlugosc++;
                    }
                }
                if(flagal==1 && flagap==0){
                    minimum=min(minimum,wejscie[indeksl]);
                    indeksl--;
                    dlugosc++;
                }
                if(flagal==0 && flagap==1){
                    minimum=min(minimum,wejscie[indeksp]);
                    indeksp++;
                    dlugosc++;
                }
            }
        }
        wynik=max(wynik,(long double)((long double)minimum/(long double)maksimum)*(long double)dlugosc);
    }

    cout<<fixed<<setprecision(6)<<wynik;
    return 0;
}