#include <bits/stdc++.h>

using namespace std;
int graf[3009][3009];
int main()
{
    std::ios_base::sync_with_stdio(0);
    int przyjaciele,znajomosci;
    cin>>przyjaciele>>znajomosci;
    int odpowiedzi[przyjaciele+1];
    for(int i=1;i<=przyjaciele;i++)
    {
        odpowiedzi[i]=1;
    }
    for(int i=1;i<=znajomosci;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a][b]=1;
        graf[b][a]=1;
    }
    /*
     for(int i=1;i<=przyjaciele;i++)
    {
        for(int j=1;j<=przyjaciele;j++)
        {
            cout<<graf[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=1;i<=przyjaciele;i++)
    {
        for(int j=i+1;j<=przyjaciele;j++)
        {
            if(graf[i][j]==0 && odpowiedzi[i]==1 && odpowiedzi[j]==1)
            {
                odpowiedzi[i]=0;
                odpowiedzi[j]=0;
            }
        }
    }
    /*
    cout<<endl;
    for(int i=1;i<=przyjaciele;i++)
    {
        cout<<odpowiedzi[i]<<" ";
    }
    cout<<endl;
    */
    int k=0;
    for(int i=1;i<=przyjaciele;i++)
    {
        if(k>=przyjaciele/3)
        {
            break;
        }
        if(odpowiedzi[i]==1)
        {
            cout<<i<<" ";
            k++;
        }
    }
    return 0;
}