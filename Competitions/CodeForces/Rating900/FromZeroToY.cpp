//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int t,x,y;
    cin>>t;
    while(t--)
    {
        long long int power=1e8,wynik=0;
        cin>>x>>y;
        while(power>0)
        {
            while((x*power)<=y)
            {
                y=y-(x*power);
                wynik++;
            }
            power=power/10;
        }
        wynik=wynik+y;
        cout<<wynik<<endl;
    }
    
    return 0;
}
 