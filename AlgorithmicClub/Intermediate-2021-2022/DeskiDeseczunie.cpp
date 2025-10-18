//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int modulo=1e9+7;

vector<vector<long long int>> matryca1(101,vector<long long int> (101,0));
vector<vector<long long int>> matryca2(101,vector<long long int> (101,0));
vector<vector<long long int>> matryca3(101,vector<long long int> (101,0));

void szybkie_potegowanie(long long int dlugosc, int deska){
    while(dlugosc){
        if(dlugosc%2!=0){
            for(int i=1;i<=deska;i++){
                for(int j=1;j<=deska;j++){
                    matryca3[i][j] = 0;
                }
            }
            for(int i=1;i<=deska;i++)
            {
                for(int j=1;j<=deska;j++)
                {
                    for(int k=1;k<=deska;k++)
                    {
                        matryca3[i][j]=(matryca3[i][j]+matryca2[i][k]*matryca1[k][j])%modulo;
                    }
                }
            }
            matryca2=matryca3;
        }

        for(int i=1;i<=deska;i++){
            for(int j=1;j<=deska;j++){
                matryca3[i][j] = 0;
            }
        }
        for(int i=1;i<=deska;i++){
            for(int j=1;j<=deska;j++){
                for(int k=1;k<=deska;k++){
                    matryca3[i][j]=(matryca3[i][j]+matryca1[i][k]*matryca1[k][j])%modulo;
                }
            }
        }
        matryca1=matryca3;

        dlugosc=dlugosc/2;
    }

    return;
}

void uzupelnij_matryce_poczatkowe(long long int deska){
    for(int i=1;i<=deska;i++){
        if(i==1){
            for(int j=1;j<=deska;j++){
                if(j==1 || j==deska){
                    matryca1[i][j]=1;
                }else{
                    matryca1[i][j]=0;
                }
            }
        }else{
            for(int j=1;j<=deska;j++){
                if(j+1==i){
                    matryca1[i][j]=1;
                }
                else{
                    matryca1[i][j]=0;
                }
            }
        }
    }

    for(int i=1;i<=deska;i++){
        matryca2[i][i]=1;
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int dlugosc,deska;
    cin>>dlugosc>>deska;

    if(dlugosc<deska){
        cout<<1;
        return 0;
    }

    uzupelnij_matryce_poczatkowe(deska);
    szybkie_potegowanie(dlugosc-deska,deska);

    long long int wynik=matryca2[1][1]*2;
    for(int i=2;i<=deska;i++){
        wynik=(wynik+matryca2[1][i])%modulo;
    }

    cout<<wynik;

    return 0;
}