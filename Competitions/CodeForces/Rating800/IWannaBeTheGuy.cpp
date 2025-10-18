//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> poziomy;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    poziomy.resize(n+1,0);
    int p1,p2;
    cin>>p1;
    for(int i=1;i<=p1;i++){
        int poziom;
        cin>>poziom;
        poziomy[poziom]=1;
    }
    cin>>p2;
    for(int i=1;i<=p2;i++){
        int poziom;
        cin>>poziom;
        poziomy[poziom]=1;
    }
    for(int i=1;i<=n;i++){
        if(poziomy[i]==0){
            cout<<"Oh, my keyboard!";
            return 0;
        }
    }

    cout<<"I become the guy.";
    return 0;
}
 