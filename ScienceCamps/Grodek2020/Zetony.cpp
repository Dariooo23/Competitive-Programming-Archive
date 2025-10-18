#include <bits/stdc++.h>

using namespace std;

char tab[300009];
int tab1[300009];
int main()
{
    int n,o;
    cin>>n>>o;
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }


    for(int i=0;i<o;i++)
    {
        int b,c;
        cin>>b>>c;
        if(tab1[b-1]==0)
            {
                tab1[b-1]=1;
            }
            else
            {
                tab1[b-1]=0;
            }
        if(tab1[c]==0)
            {
                tab1[c]=1;
            }
            else
            {
                tab1[c]=0;
            }


    }

    bool zmiana=0;

    for(int i=0;i<n;i++)
    {
        if(tab1[i]==1)
        {
            if(zmiana==0)
            {
                zmiana=1;
            }
            else
            {
                zmiana=0;
            }
        }

        if(tab[i]=='A')
        {
            if(zmiana==0)
            {
                cout<<"A";
            }
            else
            {
                cout<<"R";
            }
        }
        else
        {
           if(zmiana==0)
            {
                cout<<"R";
            }
            else
            {
                cout<<"A";
            }
        }
    }
    return 0;
}