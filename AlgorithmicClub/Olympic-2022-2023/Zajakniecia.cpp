//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> wiersz(15009);
vector<int> rowne (15009);
vector<vector<int>> ciag(2,vector<int> (15009));
vector<vector<int>> ostatni(2,vector<int> (15009));

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

    for(int j=1;j<=n;j++){
			cin>>ciag[0][j];
			ostatni[0][j]=0;
			for(int k=j-1;k>0;k--){
			    if(ciag[0][j]==ciag[0][k]){
					ostatni[0][j]=k;
					break;
				}
			}
		}


    for(int j=1;j<=m;j++){
		cin>>ciag[1][j];
		ostatni[1][j]=0;
		for(int k=j-1;k>0;k--){
			if(ciag[1][j]==ciag[1][k]){
				ostatni[1][j]=k;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
       if(ostatni[0][i]!=0){
           for(int j=1;j<=m;j++){
               if(wiersz[j-1]>wiersz[j] ||(ciag[0][i]==ciag[1][j] &&rowne[ostatni[1][j]-1]<ostatni[0][i]&&ostatni[1][j]!=0 &&wiersz[j]==wiersz[ostatni[1][j]-1] )){
                   wiersz[j]++;
                   rowne[j]=i;
               }
           }
       }
    }

	cout<<wiersz[m]*2<<endl;
}