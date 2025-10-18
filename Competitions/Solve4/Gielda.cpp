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
    
    vector<int> wejscie(n);
    vector<int> maks(n);

    for(int i=0;i<n;i++){
        cin>>wejscie[i];
    }

    maks[n-1]=wejscie[n-1];
    for(int i=n-2;i>=0;i--){
        maks[i]=max(maks[i+1],wejscie[i]);
    }

    int wynik=0;
    for(int i=0;i<n;i++){
        wynik=max(wynik,maks[i]-wejscie[i]);
    }

    cout<<wynik;
    return 0;
}