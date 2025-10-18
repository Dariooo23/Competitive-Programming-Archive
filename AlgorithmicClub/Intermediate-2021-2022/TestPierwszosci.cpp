//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<bool> pierwsze(1e7+9);

void sito()
{
    pierwsze[0]=1;
    pierwsze[1]=1;
    for(int i=2;i<=1e7+2;i++)
    {
        if(!pierwsze[i])
        {
            for(int j=i+i;j<=1e7+2;j=j+i)
            {
                pierwsze[j]=1;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    sito();

    int n;
    cin>>n;

    while(n--)
    {
        int a;
        cin>>a;
        if(!pierwsze[a])
        {
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
    }
    return 0;
}
 