#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    LL a,b,c;
    cin>>a>>b>>c;

    LL sum=a+b+c;

    if(sum%3!=0){
        cout<<"NIE"<<endl;
        return 0;
    }

    sum/=3;
    int licz=0;
    if(a!=sum)licz++;
    if(b!=sum)licz++;
    if(c!=sum)licz++;

    cout<<licz<<endl;

    return 0;
}