//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tab;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a,b;
    cin>>a>>b;

    tab.resize(a.size()+1,vector<int> (b.size()+1));

    for(int i=0;i<=a.size();i++){
        tab[i][0]=0;
    }
    for(int i=0;i<=b.size();i++){
        tab[0][i]=0;
    }

    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){

            tab[i+1][j+1]=max(tab[i+1][j],tab[i][j+1]);
            if(a[i]==b[j]){
                tab[i+1][j+1]=tab[i][j]+1;
            }
        }
    }
    cout<<tab[a.size()][b.size()]<<endl;
    
    return 0;
}