//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

string slowo;
vector<int> prefikso_sufiks;

void kmp(string slowo){
    prefikso_sufiks.resize(slowo.size()+10);
    prefikso_sufiks[0]=0;

    for(int i=1;i<slowo.size();i++) {
        int prefiks=prefikso_sufiks[i-1];

        while(prefiks>0 && slowo[prefiks]!=slowo[i]){
           prefiks=prefikso_sufiks[prefiks-1];
        }

        if(slowo[prefiks]==slowo[i]){
            prefiks++;
        }
        prefikso_sufiks[i]=prefiks;
    } 

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>slowo;
    kmp(slowo);

    for(int i=0;i<slowo.size();i++){
        cout<<prefikso_sufiks[i]<<" ";
    }
    return 0;
}
 