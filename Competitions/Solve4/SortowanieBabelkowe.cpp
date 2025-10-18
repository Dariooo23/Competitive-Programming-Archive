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
    for(int i=0;i<n;i++){
        cin>>wejscie[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(wejscie[j]>wejscie[j+1]){
                cout<<wejscie[j]<<" "<<wejscie[j+1]<<endl;
                swap(wejscie[j],wejscie[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<wejscie[i]<<" ";
    }

    return 0;
}