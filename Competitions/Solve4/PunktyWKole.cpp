//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int solve(long long int r){
    long long int licznik=0;
    long long int kopiar=r;
    for(long long int y=1;y<=r;y++){
          while(kopiar>0 && kopiar*kopiar+y*y>r*r){
              kopiar--;
          }
          licznik=licznik+kopiar;
    }
    return (licznik+r)*4+1;
}   
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int a;
    cin>>a;
    cout<<solve(a);
    return 0;
}