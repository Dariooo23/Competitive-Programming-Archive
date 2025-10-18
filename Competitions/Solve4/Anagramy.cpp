//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> zliczanieg(500,0);
vector<int> zliczaniep(500,0);

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    cin>>slowo;
    for(int i=0;i<slowo.size();i++){
        zliczanieg[slowo[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        int flaga=0;
        string wejscie;
        cin>>wejscie;

        for(int i=0;i<wejscie.size();i++){
            zliczaniep[wejscie[i]]++;
        }
        for(int i=0;i<=300;i++){
            if(zliczaniep[i]!=zliczanieg[i]){
                flaga=1;
                break;
            }
        }

        if(flaga){
            cout<<"NIE"<<'\n';
        }else{
            cout<<"TAK"<<'\n';
        }
        
        zliczaniep.clear();
        zliczaniep.resize(500,0);
    }
    return 0;
}