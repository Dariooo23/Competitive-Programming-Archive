//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,char>> zliczanie(500,{0,0});
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    cin>>slowo;

    for(int i=0;i<slowo.size();i++){
        zliczanie[slowo[i]].first++;
        zliczanie[slowo[i]].second=slowo[i];
    }

    char srodek='0';
    int dlugoscsrodka=0;
    for(int i='a';i<='z';i++){
        if(zliczanie[i].first%2==1){
            if(dlugoscsrodka<zliczanie[i].first){
                dlugoscsrodka=zliczanie[i].first;
                srodek=zliczanie[i].second;
                break;
            }
        }
    }

    for(int i='a';i<='z';i++){
        for(int j=0;j<zliczanie[i].first/2;j++){
            cout<<zliczanie[i].second;
        }
    }
    if(srodek!='0'){
        cout<<srodek;
    }
    for(int i='z';i>='a';i--){
        for(int j=0;j<zliczanie[i].first/2;j++){
                cout<<zliczanie[i].second;
        }
    }
    return 0;
}