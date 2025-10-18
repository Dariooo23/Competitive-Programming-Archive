//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    vector<int> wejscie;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        wejscie.push_back(a);
    }

    int wynikg=1,wynikp=1;
    for(int i=1;i<n;i++){
        if(wejscie[i]>wejscie[i-1]){
            wynikp++;
        }else{
            wynikg=max(wynikg,wynikp);
            wynikp=1;
        }
    }
    wynikg=max(wynikg,wynikp);

    cout<<wynikg;
    return 0;
}