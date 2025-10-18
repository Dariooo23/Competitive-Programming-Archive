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

    vector<int> oceny(101);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        oceny[a]++;
    }
    for(int i=0;i<=100;i++){
        if(oceny[i]!=0){
            cout<<i<<" "<<oceny[i]<<endl;
        }
    }
    return 0;
}