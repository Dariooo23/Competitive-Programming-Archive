#include <bits/stdc++.h>
using namespace std;
bool zlozona[1000000]={0};
int liczbyp[78498]={0};
int djlp[1000000]={0};
int prefiksy[1000000]={0};
int sito()
{
    int n=1000000;
   for (int i=2;i*i<=n;i++)
{
    if (zlozona[i]) continue;
        for (int j=i*i;j<=n;j+=i)
        {
            zlozona[j]=true;
        }

}
}


int vlp()
{
    int aa=0;
    for(int i=2;i<1000000;i++)
    {
        if(zlozona[i]==0)
        {
            liczbyp[aa]=i;
            aa++;
        }

    }
}


int lol()
{
    for (int i=0;i<78498;i++)
    {
       for(int j=liczbyp[i];j<=1000000;j=j+liczbyp[i])
       {
           djlp[j]++;
       }
    }
{

}
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    sito();
    vlp();
    lol();
    int t;
    cin>>t;
  /* for(int i=0;i<78498;i++)
    {
       cout<<liczbyp[i]<<" ";
    }*/
    for(int i=1;i<1000000;i++)
    {
       prefiksy[i]=djlp[i]+prefiksy[i-1];
    }
    /*for(int i=0;i<100000;i++)
    {
       cout<<djlp[i]<<" ";
    }*/
    for(int i=0;i<t;i++)
    {
        int a,b,wynik=0;
        cin>>a>>b;
        wynik=prefiksy[b]-prefiksy[a-1];
        cout<<wynik<<endl;
        wynik=0;
    }
    return 0;
}