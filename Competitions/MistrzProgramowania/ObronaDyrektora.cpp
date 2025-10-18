//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo1,slowo2;
    cin>>slowo1>>slowo2;

    cout<<slowo1[0];
    for(int i=1;i<slowo1.size()-1;i++){
        cout<<"*";
    }
    if(slowo1.size()>1)cout<<slowo1[slowo1.size()-1];
    cout<<" ";
    cout<<slowo2[0];
    for(int i=1;i<slowo2.size()-1;i++){
        cout<<"*";
    }
    if(slowo2.size()>1)cout<<slowo2[slowo2.size()-1];
    return 0;
}