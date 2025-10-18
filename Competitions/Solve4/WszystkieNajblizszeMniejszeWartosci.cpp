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
    vector<int> wyjscie(n);

    for(int i=0;i<n;i++){
        cin>>wejscie[i];
    }

    priority_queue<pair<int,int>> kolejka;
    for(int i=n-1;i>=0;i--){
        kolejka.push({wejscie[i],i});
        while(!kolejka.empty() && kolejka.top().first>wejscie[i]){
            wyjscie[kolejka.top().second]=wejscie[i];
            kolejka.pop();
        }
    }

    while(!kolejka.empty()){
        wyjscie[kolejka.top().second]=0;
        kolejka.pop();
    }
    for(int i=0;i<n;i++){
        cout<<wyjscie[i]<<" ";
    }
    return 0;
}