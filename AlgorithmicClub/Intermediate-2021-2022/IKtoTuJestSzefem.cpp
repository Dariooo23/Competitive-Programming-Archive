
//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int szefowie[1000000];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int pracownicy,pytania;
    cin>>pracownicy>>pytania;

    for(int i=2;i<=pracownicy;i++)
    {
        cin>>szefowie[i];
    }

    szefowie[1]=-1;
    for(int i=0;i<pytania;i++)
    {
        int x,y,dziala=0;
        cin>>x>>y;

        while(szefowie[y]>0)
        {
            if(szefowie[y]==x)
            {
                dziala=1;
            }
            y=szefowie[y];
        }

        if(dziala==1 && szefowie[y]!=0)
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