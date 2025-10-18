//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> alfabet;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    string slowo;
    cin>>slowo;

    alfabet.resize(300,0);

    for(int i=0;i<=n;i++){
        if(slowo[i]>='A' && slowo[i]<='Z'){
            slowo[i]=slowo[i]+32;
        }alfabet[slowo[i]]=1;
    }
    for(int i='a';i<='z';i++){
        if(alfabet[i]==0){
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";
    return 0;
}
 