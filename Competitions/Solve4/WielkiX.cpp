//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    pair<int,int> pozycja;
    for(int i=1;i<=n;i++){
        int licznik=0;
        for(int j=1;j<=m;j++){
            char znak;
            cin>>znak;
            if(znak=='#'){
                licznik++;
                pozycja.first=i;
                pozycja.second=j;
            }
        }
        if(licznik==1){
            cout<<pozycja.first<<" "<<pozycja.second;
            return 0;
        }
    }
    return 0;
}