//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    vector<pair<long long int,long long int>> wojewodztwa(n);
    vector<long long int> wyniki(n+1,0);

    for(long long int i=1;i<=n;i++){
        cin>>wojewodztwa[i-1].first;
        wojewodztwa[i-1].second=i;
    }

    sort(wojewodztwa.begin(),wojewodztwa.end());

    long long suma=0,poczatek=0;
    for(long long int i=0;i<n-1;i++){
        if(suma<1e18)suma=suma+wojewodztwa[i].first;
        if(suma<wojewodztwa[i+1].first){
            for(long long int j=poczatek;j<=i;j++){
                wyniki[wojewodztwa[j].second]=-1; 
            }
            poczatek=i+1;
        }
    }

    for(long long int i=1;i<=n;i++){
        if(wyniki[i]==0){
            cout<<i<<" ";
        }
    }
    return 0;
}