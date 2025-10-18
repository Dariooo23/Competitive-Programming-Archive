#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;

vector<int> g;
vector<bool> visited;

LL licz=0;

void rek(LL n,LL a,LL b,LL ost){
    if(ost>n)return;
    licz++;
    rek(n,a,b,ost*10+b);
    if(ost==0 && a==0)return;
    rek(n,a,b,ost*10+a);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    LL n,a,b;
    cin>>n>>a>>b;

    if(a==0 && b==0){
        cout<<1<<endl;
        return 0;
    }

    if(a>b)swap(a,b);
    rek(n,a,b,0);
    if(a!=0)licz--;
    cout<<licz<<endl;

    return 0;
}