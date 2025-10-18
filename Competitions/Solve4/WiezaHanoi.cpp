//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int a, int b, int c){
    if(n>0){
      hanoi(n-1,a,c,b);
      cout<<a<<" "<<c<<'\n';
      hanoi(n-1,b,a,c);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    hanoi(n,1,3,2);
    return 0;
}