//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int liczba1=1,liczba2=1;
    set<long long int> ciag;

    int flaga=0;
    ciag.insert(1);
    while(liczba1<1e18 && liczba2<1e18){
        if(flaga==0){
            liczba1=liczba1+liczba2;
            ciag.insert(liczba1);
            flaga=1;
        }else{
            liczba2=liczba2+liczba1;
            ciag.insert(liczba2);
            flaga=0;
        }
    }

    int q;
    cin>>q;
    while(q--){
        long long int liczba,licznik=0;
        cin>>liczba;

        while(liczba!=0){
            licznik++;
            auto it=ciag.upper_bound(liczba);

            long long int liczba3=*it;
            long long int roznica1=abs(liczba-liczba3);

            --it;
            long long int liczba4=*it;
            long long int roznica2=abs(liczba-liczba4);

            if(roznica1<roznica2){
                liczba=liczba-liczba3;
            }else{
                liczba=liczba-liczba4;
            }
            if(liczba<0){
                liczba=liczba*-1;
            }
        }

        cout<<licznik<<endl;
    }
    return 0;
}