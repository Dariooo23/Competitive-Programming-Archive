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

    char a,b,c;
    cin>>a>>b>>c;
    cout<<a<<" "<<b<<" ";
    if(c=='Z'){
        cout<<"A";
    }else{
        cout<<(char)(c+1);
    }
    return 0;
}