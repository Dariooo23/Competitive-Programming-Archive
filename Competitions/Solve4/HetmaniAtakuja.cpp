//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> X(n+1);
    vector<int> Y(n+1);
    vector<int> Prz1(2*n+1);
    vector<int> Prz2(2*n+1);
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        X[x]++;
        Y[y]++;
        Prz1[x-y+n]++;
        Prz2[x+y]++;
    }
    for(int i=0;i<=n;i++)
        if(X[i]>1){
            cout<<"ATAK"<<endl;
            return 0;
        }
    for(int i=0;i<=n;i++)
        if(Y[i]>1){
            cout<<"ATAK"<<endl;
            return 0;
        }
    for(int i=0;i<=2*n;i++)
        if(Prz1[i]>1){
            cout<<"ATAK"<<endl;
            return 0;
        }
    for(int i=0;i<=2*n;i++)
        if(Prz2[i]>1){
            cout<<"ATAK"<<endl;
            return 0;
        }
    cout<<"DOBRZE"<<endl;

    return 0;
}