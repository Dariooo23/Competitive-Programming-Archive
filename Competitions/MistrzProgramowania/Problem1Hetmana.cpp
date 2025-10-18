//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2 && y1==y2){
        cout<<0;
    }else{
        if(abs(x1-x2)==abs(y1-y2) || x1==x2 || y1==y2){
            cout<<1;
        }else{
            cout<<2;
        }
    }
    return 0;
}