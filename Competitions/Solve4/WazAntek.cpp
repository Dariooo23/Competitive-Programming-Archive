//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> mapa;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    mapa.resize(n,vector<char> (m,'.'));

    pair<int,int> pozycja={0,0};
    int kierunek=1;

    mapa[0][0]='#';

    int blad=0;
    while(true){
        //Ustaw sie na kolejne pole
        if(kierunek==1){
            if(pozycja.second!=m-1){
                pozycja.second++;
            }
        }
        if(kierunek==2){
            if(pozycja.first!=n-1){
                pozycja.first++;
            }
        }
        if(kierunek==3){
            if(pozycja.second!=0){
                pozycja.second--;
            }
        }
        if(kierunek==4){
            if(pozycja.first!=0){
                pozycja.first--;
            }
        }

        //Sprawdzanie ile sasiednich pol jest juz ogonem
        int licznik=0;
        if(pozycja.first!=0){
            if(mapa[pozycja.first-1][pozycja.second]=='#'){
                licznik++;
            }
        }
        if(pozycja.first!=n-1){
            if(mapa[pozycja.first+1][pozycja.second]=='#'){
                licznik++;
            }
        }
        if(pozycja.second!=0){
            if(mapa[pozycja.first][pozycja.second-1]=='#'){
                licznik++;
            }
        }
        if(pozycja.second!=m-1){
            if(mapa[pozycja.first][pozycja.second+1]=='#'){
                licznik++;
            }
        }


        //Jezeli pole niebezpieczne to cofnij sie i skrec w przeciwnym razie przejdz na nie
        if(licznik>=2){
            blad++;
            if(kierunek==1){
                pozycja.second--;
                kierunek=2;
            }else{
                if(kierunek==2){
                    pozycja.first--;
                    kierunek=3;
                }else{
                    if(kierunek==3){
                        pozycja.second++;
                        kierunek=4;
                    }else{
                        if(kierunek==4){
                            pozycja.first++;
                            kierunek=1;
                        }
                    }
                }
            }
        }else{
            blad=0;
            mapa[pozycja.first][pozycja.second]='#';
        }
        if(blad==2){
            break;
        }


        //Skrecanie gdy sciana
        if(kierunek==1 && pozycja.second==m-1){
            if(pozycja.first!=n-1){
                kierunek=2;
            }else{
                break;
            }
        }else{
            if(kierunek==2 && pozycja.first==n-1){
                if(pozycja.second!=0){
                    kierunek=3;
                }else{
                    break;
                }
            }else{
                if(kierunek==3 && pozycja.second==0){
                    if(pozycja.first!=0){
                        kierunek=4;
                    }else{
                        break;
                    }
                }else{
                    if(kierunek==4 && pozycja.first==0){
                        if(pozycja.second!=m-1){
                            kierunek=1;
                        }else{
                            break;
                        }
                    }       
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mapa[i][j];
        }cout<<endl;
    }


    return 0;
}