//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> kmr;
vector<int> sufiksy;

void fkmr(string slowo,int rozmiar)
{
    vector<pair<int, pair<int,int>>> pomoc(rozmiar);
    int logarytm=log2(rozmiar)+1,potega=1;


    for(int i=0;i<rozmiar;i++)
    {
        kmr[i][0]=slowo[i]-'a'+1;
    }

    
    for(int i=1;i<=logarytm;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            if(j+potega>=rozmiar)
            {
                pomoc[j]=make_pair(kmr[j][i-1],make_pair(-1,j));
            }
            else
            {
                pomoc[j]=make_pair(kmr[j][i-1],make_pair(kmr[j+potega][i-1],j));
            }
        }


        sort(pomoc.begin(),pomoc.end());
        pair<int,int> pomoc2=make_pair(-1,-1);
        int ile=-1;

        
        for(int j=0;j<rozmiar;j++)
        {
            if(pomoc2.first!=pomoc[j].first || pomoc2.second!=pomoc[j].second.first)
            {
                pomoc2=make_pair(pomoc[j].first,pomoc[j].second.first);
                ile++;
            }
            kmr[pomoc[j].second.second][i]=ile;
        }
        potega=potega*2;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    int rozmiar,logarytm;


    cin>>slowo;
    rozmiar=slowo.size();
    logarytm=log2(rozmiar)+1;


    kmr.resize(rozmiar+9,vector<int> (21));
    sufiksy.resize(rozmiar+9);
    fkmr(slowo,rozmiar);


    for(int i=0;i<rozmiar;i++)
    {
        sufiksy[kmr[i][logarytm]]=i+1;
    }
    for(int i=0;i<rozmiar;i++)
    {
        cout<<sufiksy[i]<<" ";
    }
    return 0;
}
 