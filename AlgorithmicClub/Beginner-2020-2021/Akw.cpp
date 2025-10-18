#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct ryb
{
    int wiek;
    double masa;
    int nr;
}ryba;
vector<ryb>V1;
vector<ryb>V2;
int prze[1000010];
bool mysort(ryb a,ryb b)
{
    if(a.masa!=b.masa)
    {
        return a.masa>b.masa;
    }
    else
    {
        return a.wiek>b.wiek;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,w;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>w;
        ryba.wiek=w;
        ryba.masa=m;
        ryba.nr=i;
        V1.push_back(ryba);

    }

    bool mati=1;
    int i=0;
    while(mati)
    {
        if(i%2==0)
        {
            V2.clear();
            sort(V1.begin(),V1.end(),mysort);
            if(V1.size()==0) mati=0;
            for(int j=0;j<V1.size()/2;j++)
            {
                ryba=V1[j];
                ryba.masa+=(V1[V1.size()-1-j].masa/2);
                V2.push_back(ryba);

            }
            for(int j=V1.size()/2;j<V1.size();j++)
            {
                ryba=V1[j];
                prze[ryba.nr]=i;
            }
        }
        else
        {
                V1.clear();
            sort(V2.begin(),V2.end(),mysort);
            if(V2.size()==0) mati=0;
            for(int j=0;j<V2.size()/2;j++)
            {
                ryba=V2[j];
                ryba.masa+=(V2[V2.size()-1-j].masa/2);
                V1.push_back(ryba);

            }
            for(int j=V2.size()/2;j<V2.size();j++)
            {
                ryba=V2[j];
                prze[ryba.nr]=i;
            }
        }
        i++;
    }

    int q,a,b;
    cin>>q;
    for(int j=0;j<q;j++)
    {
        cin>>a>>b;
        if(prze[a]>=b)
        {
            cout<<"TAK"<<endl;
        }
        else cout<<"NIE"<<endl;
    }


}