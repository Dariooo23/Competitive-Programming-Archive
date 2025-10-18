//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> czarny;
vector<int> czerwony;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 
    
    long long int n,m,wynik1=0,wynik2=0;
    cin>>n>>m;

    czarny.resize(n+1,0);
    czerwony.resize(n+1,0);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        czerwony[a]++;
        czerwony[b]++;
    }
    for(int i=1;i<=n;i++){
        czarny[i]=n-czerwony[i]-1;
    }
    for(int i=1;i<=n;i++){
        wynik1=wynik1+czerwony[i]*czarny[i];
    }

    wynik2=(n*(n-1)*(n-2))/6;
    cout<<wynik2-(wynik1/2);
    return 0;
}
 