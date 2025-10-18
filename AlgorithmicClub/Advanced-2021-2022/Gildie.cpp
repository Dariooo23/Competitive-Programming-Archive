#include <bits/stdc++.h>

using namespace std;

vector<int> graf[200009];
int rodzaj[200009]={0};

int main() {
    std::ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
        {
		int a,b;
		cin>>a>>b;
		graf[a].push_back(b);
        graf[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
        if(rodzaj[i]==0)
        {
		if(graf[i].empty())
        {
			cout<<"NIE"<<endl;
			exit(0);
		}
        rodzaj[i]=1;
		for(int j=0;j<graf[i].size();j++)
        {
           rodzaj[graf[i][j]]=2;
        }

	    }
	}

	cout<<"TAK"<<endl;
	for(int i=1;i<=n;i++)
    {
            if(rodzaj[i]==1)
            {
                cout<<"K"<<endl;
            }
            else
            {
                cout<<"S"<<endl;
            }
    }
	return 0;
}
