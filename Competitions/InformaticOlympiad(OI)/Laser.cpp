//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct punkt{
    long long int x,y,nr,pck;
};

vector<int> lewo;
vector<int> numery;
vector<int> poczatki;
vector<int> trafione;
vector<punkt> wektory;
vector<vector<int>> dp;

long long int iloczyn_wektorowy(const punkt &a, const punkt &b){
    long long int p1=a.x*b.y;
    long long int p2=a.y*b.x;
    return p1-p2;
}

bool cmp(const punkt &a, const punkt &b){
    long long int p=iloczyn_wektorowy(a,b);
    return p<0 || (p==0 && a.pck==1 && b.pck==-1);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>k>>n;

    lewo.resize(1000009);
    numery.resize(1000009);
    trafione.resize(1000009);
    poczatki.resize(1000009,1e9+9);
    dp.resize(2,vector<int>(1000009,0));

    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        punkt punkt1={a,b,i,1};
        punkt punkt2={c,d,i,-1};

        if(cmp(punkt2,punkt1)){
            swap(punkt1.pck,punkt2.pck);
        }

        wektory.push_back(punkt1);
        wektory.push_back(punkt2);
    }

    sort(wektory.begin(),wektory.end(),cmp);

    numery[0]=1;
    for(int i=1;i<2*n;i++){
        if(iloczyn_wektorowy(wektory[i-1],wektory[i])<0){
            numery[i]=numery[i-1]+1;
        }else{
            numery[i]=numery[i-1];
        }
    }

    int maks=numery[2*n-1];

    for(int i=0;i<2*n;i++){
        if(wektory[i].pck==1){
            poczatki[wektory[i].nr]=numery[i];
        }
    }

    for(int i=0;i<=maks;i++){
        lewo[i]=maks;
        trafione[i]=0;
    }

    int najdalej=maks;
    for(int i=2*n-1;i>=0;i--){
        if(wektory[i].pck==-1){
            najdalej=min(najdalej,poczatki[wektory[i].nr]);
        }
        lewo[numery[i]]=min(lewo[numery[i]],najdalej);
    }

    int licznik=0;
    for(int i=0;i<2*n;i++){
        trafione[numery[i]]=max(trafione[numery[i]],licznik);
        licznik=licznik+wektory[i].pck;
        trafione[numery[i]]=max(trafione[numery[i]],licznik);
    }

    for(int i=1;i<=k;i++){
        for(int j=1;j<=maks;j++){
            dp[i%2][j]=max(dp[i%2][j-1],dp[(i-1)%2][lewo[j]-1]+trafione[j]);
        }
    }

    cout<<dp[k%2][maks];
    return 0;
}