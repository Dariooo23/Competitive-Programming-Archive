//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int wynik=0;
void czypierwsza(long long int a){
    if(a==0 || a==1)return;

    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return;
        }
    }

    wynik++;
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int a;
    while(cin>>a){
        czypierwsza(a);
    }

    cout<<wynik;
    return 0;
}