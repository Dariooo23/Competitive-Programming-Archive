#include <bits/stdc++.h>

using namespace std;
vector<bool> visited;
vector<vector<int>> graf;
vector<int> ilosc;
vector<int> suma;
bool jeden=0,zero=0;


string dodawanie(string a, string b) {
    long long int maxrozmiar = (long long int) max(a.length(), b.length());
    long long int nadwyzka=0;

    a=string(maxrozmiar-a.length(),'0')+a;
    b=string(maxrozmiar-a.length(),'0')+b;
    string wynik=string(maxrozmiar+1,'0');

    for(int i=maxrozmiar-1;i>=0;i--)
    {
        int w=(a[i]-'0')+(b[i]-'0')+nadwyzka;
        nadwyzka=w/10;
        w=w%10;
        wynik[i+1]=wynik[i+1]+w;
    }
    wynik[0]=wynik[0]+nadwyzka;
    while(wynik[0]=='0' && wynik.length()>1)
    {
        wynik.erase(0,1);
    }
    return wynik;
}


string mnozenie(string a, string b) {
    string wynik="0";

    if(a.length()<b.length())
    {
        swap(a,b);
    }

    string wynikczesciowy;
    long long int nadwyzka=0,wiersz=0;
    long long int maxrozmiar=(long long int)(a.length()+b.length());
    for(int i =(int)(b.length()-1);i>=0;i--,wiersz++)
    {
        wynikczesciowy=string(maxrozmiar+1,'0');
        for(int j = (int) (a.length() - 1), x = 0; j >= 0; j--, x++)
        {
            long long int w=(a[j]-'0')*(b[i]-'0')+nadwyzka;
            nadwyzka=w/10;
            w=w%10;
            wynikczesciowy[maxrozmiar-wiersz-x]=wynikczesciowy[maxrozmiar-wiersz-x]+w;
        }
        wynikczesciowy[b.length()-wiersz]=wynikczesciowy[b.length()-wiersz]+nadwyzka;
        wynik=dodawanie(wynik,wynikczesciowy);
        nadwyzka = 0;
    }

    while(wynik[0]=='0' && wynik.length()>1)
    {
        wynik.erase(0,1);
    }
    return wynik;
}


void dfs(int s)
{
    if(s==0)
    {
        zero=1;
    }
    if(s==1)
    {
        jeden=1;
    }
    for(int v:graf[s])
    {
        if(visited[v]==0)
        {
            visited[v]=1;
            dfs(v);
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    int testy;
    int yes=0;
    cin>>testy;
    for(int lol=0;lol<testy;lol++)
    {
        visited.resize(26009);
        graf.resize(26009);
        ilosc.resize(26009);
        suma.resize(26009);
        ilosc.clear();
        suma.clear();
        visited.clear();
        graf.clear();
        string lewo="",prawo="";
        long long int k=0,rozmiar1=0,rozmiar2=0,licznik1=0,licznik2=0,n=0;
        bool dziala=1,stop1=0,stop2=0;
        char litera1='A';
        char litera2='A';
        cin>>k;

        for(int i=0;i<k;i++)
        {
            cin>>ilosc[i];
            if(i==0)
            {
                suma[i]=ilosc[i];
            }
            else
            {
                suma[i]=ilosc[i]+suma[i-1];
            }
        }

        cin>>rozmiar1;
        for(int i=0;i<rozmiar1;i++)
        {
            char a;
            cin>>a;
            if('a'<=a && a<='z')
            {
                for(int i=0;i<ilosc[a-'a'];i++)
                {
                    lewo=lewo+a;
                }
            }
            else
            {
                lewo=lewo+a;
            }
        }
        cin>>rozmiar2;
        for(int i=0;i<rozmiar2;i++)
        {
            char a;
            cin>>a;
            if('a'<=a && a<='z')
            {
                for(int i=0;i<ilosc[a-'a'];i++)
                {
                    prawo=prawo+a;
                }
            }
            else
            {
                prawo=prawo+a;
            }
        }
        if((lewo.size()!=prawo.size()))
        {
            cout<<"0"<<endl;
        }
        else
        {
            if(k==0 && lewo==prawo)
            {
                cout<<"1"<<endl;
            }
            else
            {
                for(int i=0;i<prawo.size();i++)
        {
            //KTORA LITERA ALFABETU I NR
            if(prawo[i]==litera2 && licznik2+1<ilosc[prawo[i]-97])
            {
                licznik2++;
            }
            else
            {
                //cout<<ilosc[prawo[i]-97]<<" ";
                licznik2=0;
                litera2=prawo[i];
            }
            if(lewo[i]==litera1 && licznik1+1<ilosc[lewo[i]-97])
            {
                licznik1++;
            }
            else
            {
                //cout<<ilosc[lewo[i]-97]<<" ";
                licznik1=0;
                litera1=lewo[i];
            }

            //ZERA I JEDYNKI
            if(prawo[i]=='0' && lewo[i]=='1')
            {
                 dziala=0;
                 break;
            }
            if(prawo[i]=='1' && lewo[i]=='0')
            {
                 dziala=0;
                 break;
            }
            if(prawo[i]=='1' && lewo[i]=='1'&&stop1==0)
            {
                stop1=1;
                graf[1].push_back(1);
            }
            if(prawo[i]=='0' && lewo[i]=='0' &&stop2==0)
            {
                stop2=1;
                graf[0].push_back(0);
            }

            //ALFABET
            if(prawo[i]!='1' && prawo[i]!='0')
            {
                    if(lewo[i]=='0' || lewo[i]=='1')
                    {
                        graf[licznik2+suma[prawo[i]-97]-ilosc[prawo[i]-97]+2].push_back(lewo[i]-48);
                        graf[lewo[i]-48].push_back(licznik2+suma[prawo[i]-97]-ilosc[prawo[i]-97]+2);
                    }
            }
            if(lewo[i]!='1' && lewo[i]!='0')
            {
                    if(prawo[i]=='0' || prawo[i]=='1')
                    {
                        graf[licznik1+suma[lewo[i]-97]-ilosc[lewo[i]-97]+2].push_back(prawo[i]-48);
                        graf[prawo[i]-48].push_back(licznik1+suma[lewo[i]-97]-ilosc[lewo[i]-97]+2);
                    }
            }
            if(lewo[i]!='1' && lewo[i]!='0' && prawo[i]!='1' && prawo[i]!='0')
            {
                graf[licznik1+suma[lewo[i]-97]-ilosc[lewo[i]-97]+2].push_back(licznik2+suma[prawo[i]-97]-ilosc[prawo[i]-97]+2);
                graf[licznik2+suma[prawo[i]-97]-ilosc[prawo[i]-97]+2].push_back(licznik1+suma[lewo[i]-97]-ilosc[lewo[i]-97]+2);
            }
            /*
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"WYPISYWANIE";
            for(int i=0;i<=100;i++)
            {
            cout<<"NUMER"<<i<<" "<<endl;
            for(int j=0;j<graf[i].size();j++)
            {
                 cout<<graf[i][j]<<" ";
            }
            cout<<endl;
            }
            */
        }

        if(dziala==0)
        {
            cout<<"0"<<endl;
        }
        else
        {

        for(int i=2;i<suma[k-1]+2;i++)
        {
            if(visited[i]==0)
            {
                dfs(i);
                if(jeden==1 && zero==1)
                {
                    dziala=0;
                    jeden=0;
                    zero=0;
                    break;
                }
                if(jeden==1 || zero==1)
                {
                    jeden=0;
                    zero=0;
                }
                else
                {
                    n++;
                }
                jeden=0;
                zero=0;
            }
        }
        if(dziala==0)
            {
                cout<<"0"<<endl;
            }
            else
            {
            string wynikdlaczesciowychpoteg[14];
            long long int potegi2[14] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
            long long int maxpotega;
            string wynik="1",b="2";

            wynikdlaczesciowychpoteg[0]=b;
            maxpotega=0;

            for(int i=1;i*2<=n;i*=2)
            {
                maxpotega++;
            }

            for(int i=1;i<=maxpotega;i++)
            {
                 wynikdlaczesciowychpoteg[i]=mnozenie(wynikdlaczesciowychpoteg[i-1],wynikdlaczesciowychpoteg[i-1]);
            }

            for(int i=maxpotega;i>=0;i--)
            {
                if(n-potegi2[i]>=0)
                {
                    wynik=mnozenie(wynik,wynikdlaczesciowychpoteg[i]);
                    n=n-potegi2[i];
                }
            }
            cout<<wynik<<endl;
            }
        }
            }

        }

    }
    return 0;
}
