//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int b;
        cin>>b;
        if(b<=7){
            cout<<"NIE"<<endl;
        }else{
            cout<<"TAK"<<endl;
        }
    }
    return 0;
}