//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tab;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,wynik=0;
    cin>>n;

    string slowo;
    cin>>slowo;

    for(int k=1;k<slowo.size();k++)
    {
        tab.resize(slowo.size()+1,vector<int> (slowo.size()+1));

        for(int i=0;i<=slowo.size();i++)
        {
            tab[i][0]=0;
        }
        for(int i=0;i<=slowo.size();i++)
        {
            tab[0][i]=0;
        }

        for(int i=0;i<=slowo.size()-k;i++)
        {
            for(int j=0;j<=k;j++)
            {
                tab[i+1][j+1]=max(tab[i+1][j],tab[i][j+1]);
                if(slowo[i]==slowo[slowo.size()-k+j])
                {
                    tab[i+1][j+1]=tab[i][j]+1;
                }
            }
        }

        wynik=max(wynik,tab[slowo.size()-k][k]);
        tab.clear();
    }
    cout<<n-wynik*2;

    return 0;
}