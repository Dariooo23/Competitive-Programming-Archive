//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<bool> pierwsze;
int n,ilosc=0;

void sito(int n)
{
    pierwsze[0]=1;
    pierwsze[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!pierwsze[i])
        {
            ilosc++;
            for(int j=i+i;j<=n;j=j+i)
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

    cin>>n;

    pierwsze.resize(n+1);

    sito(n);

    cout<<ilosc<<endl;
    for(int i=2;i<=n;i++)
    {
        if(!pierwsze[i])
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
 