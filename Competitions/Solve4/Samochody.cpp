//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int a;
    cin>>a;

    vector<long long int> wejscie(a);

    for(int i=0;i<a;i++){
        cin>>wejscie[i];
    }

    vector<long long int> prefiks(a+1);
    prefiks[a]=0;
    for(int i=a-1;i>=0;i--){
        if(wejscie[i]==1){
            prefiks[i]=prefiks[i+1]+1;
        }else{
            prefiks[i]=prefiks[i+1];
        }
    }

    long long int wynik=0;
    for(int i=0;i<a;i++){
        if(wejscie[i]==0){
            wynik=wynik+prefiks[i];
        }
    }

    cout<<wynik;

    return 0;
}