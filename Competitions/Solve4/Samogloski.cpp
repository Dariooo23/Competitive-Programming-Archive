//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string slowo;
    cin>>slowo;
    int wynik=0;
    for(int i=0;i<slowo.size();i++){
        if(slowo[i]=='a' || slowo[i]=='i' || slowo[i]=='e' || slowo[i]=='o' || slowo[i]=='u'){
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}