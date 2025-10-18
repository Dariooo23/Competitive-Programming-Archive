//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void wzorcowka(int n){
    vector<vector<int>> cykle;
    vector<vector<int>> cykle2;
    vector<int> visited;
    vector<int> tab;

    tab.resize(n+1);
    cykle.resize(n+1);
    visited.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>tab[i];
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==1)continue;

        visited[i]=1;
        visited[tab[i]]=1;

        vector<int> cykl;
        cykl.push_back(tab[i]);
        int punkt=tab[tab[i]];

        while(punkt!=tab[i]){
            cykl.push_back(punkt);
            visited[punkt]=1;
            punkt=tab[punkt];
        }

        if(cykl.size()%2==0){
            if(cykle[cykl.size()].size()==0){
                cykle[cykl.size()]=cykl;
            }else{
                vector<int> cykl2;
                int indeks1=0,indeks2=0;
                while(indeks2!=cykl.size()){
                    if(indeks1<=indeks2){
                        cykl2.push_back(cykle[cykl.size()][indeks1]);
                        indeks1++;
                    }else{
                        cykl2.push_back(cykl[indeks2]);
                        indeks2++;
                    }
                }

                cykle2.push_back(cykl2);
                cykl2.clear();
                cykle[cykl.size()].clear();
            }
        }else{
            vector<int> cykl2;
            int indeks=0;

            cykl2.push_back(cykl[indeks]);
            for(int i=1;i<cykl.size();i++){
                indeks=(indeks+((cykl.size()-1)/2)+1)%cykl.size();
                cykl2.push_back(cykl[indeks]);
            }

            cykle2.push_back(cykl2);
            cykl2.clear();
        }
    }

    for(int i=1;i<=n;i++){
        if(cykle[i].size()!=0){
            cout<<"NIE";
            return;
        }
    }
    cout<<"TAK"<<endl;

    vector<int> wynik(n+1);
    for(int i=0;i<cykle2.size();i++){
        wynik[cykle2[i][cykle2[i].size()-1]]=cykle2[i][0];
        for(int j=0;j<cykle2[i].size()-1;j++){
            wynik[cykle2[i][j]]=cykle2[i][j+1];
        }
    }

    for(int i=1;i<=n;i++){
        cout<<wynik[i]<<" ";
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    wzorcowka(n);

    return 0;
}
