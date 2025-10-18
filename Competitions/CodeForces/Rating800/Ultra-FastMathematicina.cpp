//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string slowo1,slowo2;
    cin>>slowo1>>slowo2;

    for(int i=0;i<slowo1.size();i++){
        if(slowo1[i]==slowo2[i]){
            cout<<"0";
        }else{
            cout<<"1";
        }
    }
    return 0;
}
 