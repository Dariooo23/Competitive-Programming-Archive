#include<bits/stdc++.h>

using namespace std;

constexpr int M=1<<17;

int val[M+7];
int dp[M][21];

void compute(int v, int k, int level){
	if(!k) return;

	dp[v][1]=val[v];

	if(level==1) return;

	compute(2*v,k-1,level-1);
	compute((2*v)+1,k-1,level-1);

	for(int i=2; i<=k; i++){
		for(int j=0; j<i; j++) dp[v][i]=max(dp[v][i],dp[2*v][j]+dp[2*v+1][i-j-1]+val[v]);
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,k,a,b,v;

	cin>>n>>k;
	k/=2;

	v=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<(1<<i); j++){
			v++;
			cin>>a>>b;
			val[v]=a+b;
		}
	}

	compute(1,k,n);

	cout<<dp[1][k];

	return 0;
}