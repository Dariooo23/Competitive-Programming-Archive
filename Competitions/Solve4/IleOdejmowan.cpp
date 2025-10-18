//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int wynik=0;
long long int nwd(int a,int b){
    if(b==0)return a;
    wynik=wynik+a/b;
    return nwd(b,a%b);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int a,b;
    cin>>a>>b;
    nwd(a,b);
    cout<<wynik;
    return 0;
}