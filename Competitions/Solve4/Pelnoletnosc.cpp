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
    int wynik=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a>=18){
            wynik++;
        }
    }
    cout<<wynik;
    return 0;
}