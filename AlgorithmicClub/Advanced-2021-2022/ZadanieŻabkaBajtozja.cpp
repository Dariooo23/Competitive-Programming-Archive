#include <bits/stdc++.h>

using namespace std;
vector<pair<long long int,long long int>> kamienie(1000009);
pair<long long int,long long int> wszaby;
vector<long long int> graf[1009];
bool visited[1000009]={0};
long long  maksimum=0;
long long  odleglosc(long long int x1,long long int y1,long long int  x2,long long int y2)
{
    return (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}
void DFS(int punkt)
{

    long long int odleglosc1=odleglosc(kamienie[punkt].first,kamienie[punkt].second,wszaby.first,wszaby.second);
    if(odleglosc1>maksimum)
    {
        maksimum=odleglosc1;
    }
    //cout<<odleglosc1<<"odeglosc"<<" "<<kamienie[punkt].first<<" "<<kamienie[punkt].second<<endl;

    for(int  v : graf[punkt])
    {
        if(visited[v]==0)
        {
            visited[v]=1;
            DFS(v);

        }

    }

}
int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int ilosc,zaba,skok;
    cin>>ilosc>>zaba>>skok;
    zaba=zaba-1;
    for(int i=0;i<ilosc;i++)
    {
        cin>>kamienie[i].first>>kamienie[i].second;
    }
    wszaby.first=kamienie[zaba].first;
    wszaby.second=kamienie[zaba].second;
    for(int i=0;i<ilosc;i++)
    {
        for(int j=0;j<ilosc;j++)
        {
            if(j!=i)
            {
                long long int odleglosc2=odleglosc(kamienie[i].first,kamienie[i].second,kamienie[j].first,kamienie[j].second);
                if(odleglosc2<=(skok*skok))
                {
                    //cout<<j<<" ";
                    graf[i].push_back(j);
                }
            }
        }
        //cout<<endl;
    }
    /*cout<<endl;
    for(int i=1;i<=graf[zaba].size();i++)
    {
        cout<<kamienie[i].first<<" "<<kamienie[i].second<<endl;
    }*/
    DFS(zaba);
    
    cout<<fixed<<setprecision(3)<<sqrt(maksimum)+skok;



    return 0;
}