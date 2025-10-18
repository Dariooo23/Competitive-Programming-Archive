//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct prostokat{
    int x1,y1,x2,y2;
};

vector<prostokat> prostokaty;
vector<pair<long long int,prostokat>> prefiksy;
vector<pair<long long int,prostokat>> sufiksy;

pair<long long int,prostokat> wspolne_pole_prostokatow(const prostokat &prostokat1, const prostokat &prostokat2)
{
    int x1=max(prostokat1.x1,prostokat2.x1),y1=max(prostokat1.y1,prostokat2.y1);
    int x2=min(prostokat1.x2,prostokat2.x2),y2=min(prostokat1.y2,prostokat2.y2);

    int bok1=x2-x1;
    int bok2=y2-y1;

    pair<long long int,prostokat> wyjscie;
    wyjscie.first=(long long int)bok1*bok2;
    wyjscie.second.x1=x1;
    wyjscie.second.y1=y1;
    wyjscie.second.x2=x2;
    wyjscie.second.y2=y2;

    if(bok1<0)
    {
        wyjscie.first=0;
    }
    if(bok2<0)
    {
        wyjscie.first=0;
    }

    return wyjscie;
}

void stworz_prefiksy()
{
    long long int pole=(prostokaty[0].x2-prostokaty[0].x1)*(prostokaty[0].y2-prostokaty[0].y1);

    prefiksy[0].first=pole;
    prefiksy[0].second=prostokaty[0];

    for(int i=1;i<prostokaty.size();i++)
    {
        pair<long long int,prostokat> wyjscie=wspolne_pole_prostokatow(prefiksy[i-1].second,prostokaty[i]);
        prefiksy[i]=wyjscie;
    }
}
void stworz_sufiksy()
{
    long long int pole=(prostokaty[prostokaty.size()-1].x2-prostokaty[prostokaty.size()-1].x1)*
                       (prostokaty[prostokaty.size()-1].y2-prostokaty[prostokaty.size()-1].y1);
    
    sufiksy[prostokaty.size()-1].first=pole;
    sufiksy[prostokaty.size()-1].second=prostokaty[prostokaty.size()-1];

    for(int i=prostokaty.size()-2;i>=0;i--)
    {
        pair<long long int,prostokat> wyjscie=wspolne_pole_prostokatow(sufiksy[i+1].second,prostokaty[i]);
        sufiksy[i]=wyjscie;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int ilosc,wynik=0;
    cin>>ilosc;

    prefiksy.resize(ilosc);
    sufiksy.resize(ilosc);

    for(int i=1;i<=ilosc;i++)
    {
        int xx1,xx2,yy1,yy2;
        cin>>xx1>>yy1>>xx2>>yy2;
        prostokaty.push_back({xx1,yy1,xx2,yy2});
    }

    stworz_prefiksy();
    stworz_sufiksy();

    for(int i=0;i<=prostokaty.size();i++)
    {
        prostokat prostokat1,prostokat2;

        if(i+1>=prostokaty.size())
        {
            prostokat2=prefiksy[i-1].second;;
        }
        else
        {
            prostokat2=sufiksy[i+1].second;
        }
        if(i-1<0)
        {
            prostokat1=sufiksy[i+1].second;
        }
        else
        {
            prostokat1=prefiksy[i-1].second;
        }
        pair<long long int,prostokat> wyjscie=wspolne_pole_prostokatow(prostokat1,prostokat2);
        wynik=wynik+wyjscie.first-prefiksy[prostokaty.size()-1].first;
    }
    cout<<wynik+prefiksy[prostokaty.size()-1].first;

    return 0;
}
 