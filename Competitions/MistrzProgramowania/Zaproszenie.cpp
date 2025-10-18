//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    char znak1,znak2;
    int rozmiar1,rozmiar2;

    cin>>rozmiar1>>rozmiar2;

    vector<vector<char>> zaproszenie1(rozmiar1,vector<char>(rozmiar1));

    for(int i=0;i<rozmiar1;i++){
        for(int j=0;j<rozmiar1;j++){
            cin>>zaproszenie1[i][j];
        }
    }

    znak1=zaproszenie1[0][0];
    znak2=zaproszenie1[1][1];

    for(int i=1;i<=rozmiar2;i++){
        for(int j=1;j<=rozmiar2;j++){
            if(i==1 || i==rozmiar2 || j==1 || j==rozmiar2){
                cout<<znak1;
            }else{
                cout<<znak2;
            }
        }cout<<endl;
    }
    return 0;
}