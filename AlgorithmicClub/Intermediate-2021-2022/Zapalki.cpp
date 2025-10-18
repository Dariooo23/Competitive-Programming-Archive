#include <iostream>


using namespace std;

int wys[1000000];
int pref[1000000];
int suf[1000000];
int wyn[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
int n,wynik=0;
cin>>n;
for(int i=0;i<n;i++) cin>>wys[i];
pref[0]=1;
for(int i=1;i<n;i++)
{
    if(wys[i-1]<=wys[i])
    {
        pref[i]=pref[i-1]+1;
    }
    else
    {
        pref[i]=1;
    }


}
suf[n-1]=1;
for(int i=n-1;i>=0;i--)
{
    if(wys[i+1]<=wys[i])
    {
        suf[i]=suf[i+1]+1;
    }
    else
    {
        suf[i]=1;
    }


}
for(int i=0;i<n;i++)
{
    wyn[i]=pref[i]+suf[i]-1;
}
for(int i=0;i<n;i++)
{
    if(wyn[i]>wynik)
    {
        wynik=wyn[i];
    }
}
cout<<wynik;

}