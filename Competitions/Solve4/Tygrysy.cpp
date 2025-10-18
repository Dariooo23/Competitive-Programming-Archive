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

    vector<long long int> wejscie(n);

    for(int i=0;i<n;i++){
        cin>>wejscie[i];
    }

    sort(wejscie.begin(),wejscie.end());

    int wynik=0;
    for(int i=0;i<n;i++){
        int l=i,r=n-1,mid;
        while(l<r){
            int mid=(l+r+1)/2;
            if(wejscie[mid]>=wejscie[i]*2){
                r=mid-1;
            }else{
                l=mid;
            }
        }
        wynik=max(wynik,l-i+1);
    }

    cout<<wynik;
    return 0;
}