//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int dlugosc,deska;
const long long int modulo=1e9+7;

vector<vector<long long int>> macierz(101,vector<long long int> (101,0));
vector<vector<long long int>> macierz_neut(101,vector<long long int> (101,0));

void uzupelnij_matryce_poczatkowe(long long int deska){
    for(int i=1;i<=deska;i++){
        if(i==1){
            for(int j=1;j<=deska;j++){
                if(j==1 || j==deska){
                    macierz[i][j]=1;
                }else{
                    macierz[i][j]=0;
                }
            }
        }else{
            for(int j=1;j<=deska;j++){
                if(j+1==i){
                    macierz[i][j]=1;
                }
                else{
                    macierz[i][j]=0;
                }
            }
        }
    }
    for(int i=1;i<=deska;i++){
        macierz_neut[i][i]=1;
    }
    return;
}

vector<vector<long long int>> mnozenie_macierz
(vector<vector<long long int>> macierz1,
vector<vector<long long int>> macierz2, long long int deska){

    vector<vector<long long int>> macierz3(101,vector<long long int> (101,0));
    for(int i=1;i<=deska;i++){
        for(int j=1;j<=deska;j++){
            for(int k=1;k<=deska;k++){
                        macierz3[i][j]=(macierz3[i][j]+macierz2[i][k]*macierz1[k][j])%modulo;
                    }
                }
            }

    return macierz3;
}

vector<vector<long long int>> potega(long long int a,vector<vector<long long int>> macierz){
    if(a==0){
        return macierz_neut;
    }

    if(a%2==0){
        vector<vector<long long int>> wynik=potega(a/2,macierz);
        return mnozenie_macierz(wynik,wynik,deska);
    }else{
        return mnozenie_macierz(macierz,potega(a-1,macierz),deska);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>dlugosc>>deska;
    if(dlugosc<deska){
        cout<<1;
        return 0;
    }

    uzupelnij_matryce_poczatkowe(deska);
    macierz=potega(dlugosc,macierz);
    cout<<macierz[1][1];
    return 0;
}