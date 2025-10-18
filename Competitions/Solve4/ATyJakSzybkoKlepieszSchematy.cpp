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
    int a=1,b=1;

    while(true){
        if(n%(a+b)==0){
            cout<<a+b;
            return 0;
        }else{
            if(n<a+b){
                cout<<a+b;
                return 0;
            }else{
                int c=b;
                b=a+b;
                a=c;
            }
        }
    }
    return 0;
}