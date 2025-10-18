//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
 int krasnale[1000009]={0};
 int pewniaczki[100009]={0};
 bool liczby[1000009]={0};
 vector<int> pary;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>krasnale[i];
    }

    for(int i=0;i<a-1;i=i+2)
    {
        if(pewniaczki[i+1]==0)
        {
            if(liczby[krasnale[i]]==0)
            {
                pewniaczki[i+1]=krasnale[i];
                liczby[krasnale[i]]=1;
            }
            else
            {
                cout<<"0";
                exit(0);
            }
        }
        else
        {
            if(pewniaczki[i+1]!=krasnale[i])
            {
                cout<<"0";
                exit(0);
            }
        }
        if(krasnale[i]==krasnale[i+2])
        {
            break;
        }
    }
    for(int i=a-1;i>0;i=i-2)
    {
        if(pewniaczki[i-1]==0)
        {
            if(liczby[krasnale[i]]==0)
            {
                pewniaczki[i-1]=krasnale[i];
                liczby[krasnale[i]]=1;
            }
            else
            {
                cout<<"0";
                exit(0);
            }
        }
        else
        {
            if(pewniaczki[i-1]!=krasnale[i])
            {
                cout<<"0";
                exit(0);
            }
        }
        if(krasnale[i]==krasnale[i-2])
        {
            break;
        }
    }
     for(int i=0;i<a-2;i++)
    {
        if(krasnale[i]==krasnale[i+2])
        {
            if(pewniaczki[i+1]==0)
            {
                if(liczby[krasnale[i]]==0)
                {
                   pewniaczki[i+1]=krasnale[i];
                   liczby[krasnale[i]]=1;
                }
                else
                {
                    cout<<"0";
                    exit(0);
                }
            }
            else
            {
                if(pewniaczki[i+1]!=krasnale[i])
                {
                    cout<<"0";
                    exit(0);
                }
            }
      }
    }
    /*for(int i=0;i<a;i++)
    {
        cout<<pewniaczki[i]<<" ";
    }
    cout<<endl;*/
    int ostatnia=0;
    while(true)
    {
        int rozmiar=0,j=0;
        bool flaga=1;
        for(int i=ostatnia;i<a;i++)
        {
            if(pewniaczki[i]==0)
            {
                flaga=0;
                j=i;
                ostatnia=i;
                break;
            }
        }
        if(flaga==1)
        {
            break;
        }
        for(int i=j;i<a;i=i+2)
        {
            if(pewniaczki[i]==0)
            {
                rozmiar++;
                pewniaczki[i]=-1;
            }
            else
            {
                break;
            }
        }
        pary.push_back(rozmiar);
    }
    long long int silnia=1,modulo=1e9+7;
    for(int i=1;i<=pary.size();i++)
    {
        silnia=(silnia*i)%modulo;
    }
    //cout<<silnia<<" ";
    for(int i=0;i<pary.size();i++)
    {
        silnia=(silnia*pary[i])%modulo;
    }
    //cout<<silnia<<" ";
    /*for(int i=0;i<a;i++)
    {
        cout<<pewniaczki[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<pary.size();i++)
    {
        cout<<pary[i]<<" ";
    }
    cout<<endl;*/
    cout<<silnia;
    return 0;
}