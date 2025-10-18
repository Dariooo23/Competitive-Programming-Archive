//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> tab;
vector<int> lazy;

void wzorcowka(int n,int m){
    int pierwiastek=sqrt(n)+1;
    vector<vector<int>> ilosci;

    lazy.resize(n/pierwiastek+10,0);
    ilosci.resize(n/pierwiastek+10,vector<int> (100009,0));

    for(int i=0;i<n;i++){
        ilosci[i/pierwiastek][tab[i]]++;
    }

    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        b--;
        c--;

        if(a==1){
            int wynik=0;
            int pocz=b/pierwiastek,kon=c/pierwiastek;

            if(lazy[pocz]!=0){
                for(int j=0;j<pierwiastek;j++){
                    ilosci[pocz][tab[j+pocz*pierwiastek]]--;
                    tab[j+pocz*pierwiastek]=lazy[pocz];
                    ilosci[pocz][tab[j+pocz*pierwiastek]]++;
                }
                lazy[pocz]=0;
            }
            if(lazy[kon]!=0){
                for(int j=0;j<pierwiastek;j++){
                    ilosci[kon][tab[j+kon*pierwiastek]]--;
                    tab[j+kon*pierwiastek]=lazy[kon];
                    ilosci[kon][tab[j+kon*pierwiastek]]++;
                }
                lazy[kon]=0;
            }
            

            if(pocz==kon){
                for(int j=b;j<=c;j++){
                    if(tab[j]==d)wynik++;
                }
            }else{
                for(int j=b;j<(pocz+1)*pierwiastek;j++){
                    if(tab[j]==d)wynik++;
                }
                for(int j=pocz+1;j<kon;j++){
                    if(lazy[j]==d){
                        wynik=wynik+pierwiastek;
                    }else{
                        if(lazy[j]==0){
                            wynik=wynik+ilosci[j][d];
                        }
                    }
                }
                for(int j=kon*pierwiastek;j<=c;j++){
                    if(tab[j]==d)wynik++;
                }
            }

            cout<<wynik<<endl;
        }else{
            int pocz=b/pierwiastek,kon=c/pierwiastek;
            if(lazy[pocz]!=0){
                for(int j=0;j<pierwiastek;j++){
                    ilosci[pocz][tab[j+pocz*pierwiastek]]--;
                    tab[j+pocz*pierwiastek]=lazy[pocz];
                    ilosci[pocz][tab[j+pocz*pierwiastek]]++;
                }
                lazy[pocz]=0;
            }
            if(lazy[kon]!=0){
                for(int j=0;j<pierwiastek;j++){
                    ilosci[kon][tab[j+kon*pierwiastek]]--;
                    tab[j+kon*pierwiastek]=lazy[kon];
                    ilosci[kon][tab[j+kon*pierwiastek]]++;
                }
                lazy[kon]=0;
            }

            if(pocz==kon){
                for(int j=b;j<=c;j++){
                    ilosci[pocz][tab[j]]--;
                    tab[j]=d;
                    ilosci[pocz][tab[j]]++;
                }
            }else{
                for(int j=b;j<(pocz+1)*pierwiastek;j++){
                    ilosci[pocz][tab[j]]--;
                    tab[j]=d;
                    ilosci[pocz][tab[j]]++;
                }
                for(int j=pocz+1;j<kon;j++){
                    lazy[j]=d;
                }
                for(int j=kon*pierwiastek;j<=c;j++){
                    ilosci[kon][tab[j]]--;
                    tab[j]=d;
                    ilosci[kon][tab[j]]++;
                }
            }

        }
    }

    return;
}

int  main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int  n,m;
    cin>>n>>m;

    tab.resize(n);

    for(int i=0;i<n;i++){
        cin>>tab[i];
    }

    wzorcowka(n,m);
    
    return 0;
}