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
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==5){
            cout<<"TAK";
            return 0;
        }
    }

    cout<<"NIE";
    return 0;
}