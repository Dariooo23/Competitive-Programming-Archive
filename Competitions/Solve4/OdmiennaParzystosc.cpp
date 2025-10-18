//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int parzyste=0,liczba1,liczba2,n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a%2==0){
            parzyste++;
            liczba1=a;
        }else{
            liczba2=a;
        }
    }
    if(parzyste==1){
        cout<<liczba1;
    }else{
        cout<<liczba2;
    }
    return 0;
}