//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> pierwsze;
vector<long long int> pierwszeliczby;

void sito(int n){
    pierwsze.resize(2000009);
    pierwsze[0]=1;
    pierwsze[1]=1;

    for(int i=2;i*i<=n;i++){
        if(pierwsze[i]==0){
            for(int j=i*i;j<=n;j=j+i){
                pierwsze[j]=1;
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n;
    cin>>n;

    sito(2000000);
    for(int i=1;i<=2000000;i++){
        if(pierwsze[i]==0){
            pierwszeliczby.push_back(i);
        }
    }

    cout<<pierwszeliczby[n]*pierwszeliczby[n];
    
    return 0;
}