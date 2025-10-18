//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int a,b;
    cin>>a>>b;
    
    int wynik=-1;
    while(b!=0){
        b=b/a;
        wynik++;
    }

    cout<<wynik;
    return 0;
}