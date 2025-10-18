//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> smoki;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a,b,c,d,e,wynik=0;
    cin>>a>>b>>c>>d>>e;

    smoki.resize(e+1);

    for(int i=a;i<=e;i=i+a){
        smoki[i]=1;
    }
    for(int i=b;i<=e;i=i+b){
        smoki[i]=1;
    }
    for(int i=c;i<=e;i=i+c){
        smoki[i]=1;
    }
    for(int i=d;i<=e;i=i+d){
        smoki[i]=1;
    }

    for(int i=1;i<=e;i++){
        if(smoki[i]==1){
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}
 