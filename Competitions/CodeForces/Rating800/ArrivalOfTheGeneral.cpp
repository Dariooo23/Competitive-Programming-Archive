//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> wysokosci;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    int min=1e9,indeks1,max=-1e9,indeks2;
    wysokosci.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>wysokosci[i];
    }
    for(int i=1;i<=n;i++){
        if(wysokosci[i]>max){
            max=wysokosci[i];
            indeks2=i;
        }
    }
    for(int i=n;i>=1;i--){
        if(wysokosci[i]<min){
            min=wysokosci[i];
            indeks1=i;
        }
    }

    if(indeks2>indeks1){
        cout<<indeks2-1+n-indeks1-1;
    }else{
        cout<<indeks2-1+n-indeks1;
    }

    return 0;
}
 