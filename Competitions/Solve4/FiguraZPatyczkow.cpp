// Karol Dziekan
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
    long long int suma=0,maksimum=0;
    for(int i=0;i<n;i++){
        cin>>wejscie[i];
        suma=suma+wejscie[i];
        maksimum=max(maksimum,wejscie[i]);
    }

    if(suma-maksimum>maksimum){
        cout<<"TAK";
    }else{
        cout<<"NIE";
    }
    return 0;
}
