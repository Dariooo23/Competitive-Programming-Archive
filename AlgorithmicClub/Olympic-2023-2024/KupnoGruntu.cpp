//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<long long int>> sum_pref;

long long int cena(long long int x1,long long int y1,long long int x2,long long int y2){
	return sum_pref[x2][y2]-sum_pref[x1-1][y2]-sum_pref[x2][y1-1]+sum_pref[x1-1][y1-1];
}

void solve(long long int k,long long int x1,long long int y1,long long int x2,long long int y2){
	for(int y=y1;y<=y2;y++)
		for(int x=x1;x<=x2;x++){
			long long int suma=cena(x1, y1, x, y);

			if(k<=suma){
                cout<<x1<<" "<<y1<<" "<<x<<" "<<y;
				return;
			}
		}
}

struct point{
	long long int x,y;
};

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

	int k,n;
	cin>>k>>n;

    vector<long long int> y1(n+1,1);
    sum_pref.resize(n+1,vector<long long int> (n+1));

	for(int x=0;x<=n;x++){
		sum_pref[x][0]=0;
    }

	for(int y=1;y<=n;y++){
		long long int sx=0;
		stack<point> stos;
		stos.push({0,y+1});

		for(int x=0;x<=n;x++){
			sum_pref[x][y]=sx+sum_pref[x][y-1];
			long long int a;

			if(x<n){
				cin>>a;
            }else{
				a=2*k+1;
            }

			sx=sx+a;

			if(a>2*k){
				y1[x]=y+1;
            }else{
                if(a>=k){
                    cout<<x+1<<" "<<y<<" "<<x+1<<" "<<y;
			    	return 0;
			    }
            }

			long long int x1=x+1;
			while(y1[x]>stos.top().y){
				x1=stos.top().x;
				int y0=stos.top().y;
				stos.pop();

				long long int suma=cena(x1,y0,x,y);

				if(k<=suma){
					solve(k,x1,y0,x,y);
					return 0;
				}
			}

			if(stos.top().y>y1[x]){
				stos.push({x1,y1[x]});
            }
		}
	}

    cout<<"NIE";
	return 0;
}
