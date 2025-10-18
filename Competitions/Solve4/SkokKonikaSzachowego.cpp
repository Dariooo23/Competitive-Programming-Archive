//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string miejsce1,miejsce2;
    cin>>miejsce1>>miejsce2;

    if((abs(miejsce1[0]-miejsce2[0])==2 && abs(miejsce1[1]-miejsce2[1])==1) 
    || (abs(miejsce1[0]-miejsce2[0])==1 && abs(miejsce1[1]-miejsce2[1])==2)){
        cout<<"TAK";
    }else{
        cout<<"NIE";
    }
    return 0;
}