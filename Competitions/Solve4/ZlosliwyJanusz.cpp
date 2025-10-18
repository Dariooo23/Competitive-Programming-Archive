//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> modulo;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    modulo.resize(m+1);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        modulo[a%m]++;
    }

    int wynik=0;
    if(m%2==0){
        for(int i=1;i<m/2;i++){
            wynik=wynik+max(modulo[i],modulo[m-i]);
        }

        if(modulo[m/2]!=0)wynik++;
        if(modulo[0]!=0)wynik++;
        cout<<wynik;
        return 0;
    }else{
        for(int i=1;i<=m/2;i++){
            wynik=wynik+max(modulo[i],modulo[m-i]);
        }

        if(modulo[0]!=0)wynik++;
        cout<<wynik;
        return 0;
    }
}
