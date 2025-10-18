//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;


bool solve(long long int srednica,long long int ruch)
{
    long long int pierwiastek=sqrtl(srednica*srednica/2);
    pierwiastek=pierwiastek-pierwiastek%ruch;
    return(((pierwiastek*pierwiastek)+(pierwiastek+ruch)*(pierwiastek+ruch))>(srednica*srednica));
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int testy;
    cin>>testy;
    while(testy--)
    {
        long long int r,k;
        cin>>r>>k;
        if(solve(r,k))
        {
            cout<<"Rotkiw"<<endl;
        }
        else
        {
            cout<<"Anilorak"<<endl;
        }
    }
    
    return 0;
}
 