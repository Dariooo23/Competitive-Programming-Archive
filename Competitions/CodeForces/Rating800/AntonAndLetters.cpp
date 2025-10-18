//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> alfabet;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int wynik=0;
    char nawias;
    cin>>nawias;

    alfabet.resize(300,0);

    string ciag;
    while(cin>>ciag){
        if(ciag.size()==1)break;
        if(alfabet[ciag[0]]==0){
            alfabet[ciag[0]]=1;
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}
 