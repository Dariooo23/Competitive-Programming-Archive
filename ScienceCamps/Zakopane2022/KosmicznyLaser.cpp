//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct punkt{
    int x,y;
};

vector<punkt> asteroidy;

long long int iloczyn_wektorowy(const punkt &a, const punkt &b, const punkt &c)
{
    long long int x1 = c.x - a.x;
    long long int y1 = c.y - a.y;
    long long int x2 = c.x - b.x;
    long long int y2 = c.y - b.y;

    if (x1 * y2 - x2 * y1 > 0)
    {
        return 1;
    }
    if (x1 * y2 - x2 * y1 < 0)
    {
        return -1;
    }
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        punkt a;
        cin>>a.x>>a.y;
        asteroidy.push_back(a);
    }

    int wynik=0;

    for(int i=0;i<20;i++)
    {
        int ii=rand()%n;
        for(int j=0;j<20;j++)
        {
            int jj=rand()%n;
            int licznik=2;
            for(int k=0;k<asteroidy.size();k++)
            {
                if(k!=ii && k!=jj && ii!=jj)
                {
                    punkt a=asteroidy[ii];
                    punkt b=asteroidy[jj];
                    punkt c=asteroidy[k];

                    if(iloczyn_wektorowy(a,b,c)==0)
                    {
                        licznik++;
                    }
                }

            }
            wynik=max(wynik,licznik);
        }
    }
    cout<<wynik;
    return 0;
}
 