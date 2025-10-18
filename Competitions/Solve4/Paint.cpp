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

    int wynik=1;
    for(int i=0;i<slowo.size();i++){
        if(slowo[i]=='a' || slowo[i]=='A'){
            wynik++;
        }
        if(slowo[i]=='b'){
            wynik++;
        }
        if(slowo[i]=='B'){
            wynik++;
            wynik++;
        }
        if(slowo[i]=='d' || slowo[i]=='D'){
            wynik++;
        }
        if(slowo[i]=='e'){
            wynik++;
        }
        if(slowo[i]=='g'){
            wynik++;
        }
        if(slowo[i]=='o' || slowo[i]=='O'){
            wynik++;
        }
        if(slowo[i]=='p' || slowo[i]=='P'){
            wynik++;
        }
        if(slowo[i]=='q' || slowo[i]=='Q'){
            wynik++;
        }
        if(slowo[i]=='R'){
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}