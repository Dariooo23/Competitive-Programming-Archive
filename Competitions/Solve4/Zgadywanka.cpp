//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    long long int l=1,r=n,mid=1;
    char odpowiedz;
    while(l<=r){
        mid=(l+r)/2;

        cout<<mid<<endl;
        cin>>odpowiedz;

        if(odpowiedz=='<'){
            r=mid;
        }
        if(odpowiedz=='>'){
            l=mid+1;
        }
        if(odpowiedz=='='){
            return 0;
        }
    }
}