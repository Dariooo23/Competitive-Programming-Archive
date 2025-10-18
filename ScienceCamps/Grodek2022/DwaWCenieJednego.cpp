//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct sasiad{
    long long int x,y,nr;
};
vector<sasiad> sasiedzi;

bool cmpx(const sasiad &a,const sasiad &b)
{
    return a.x<b.x;
}
bool cmpy(const sasiad &a,const sasiad &b)
{
    return a.y<b.y;
}

void wzorcowka(int n)
{
    vector<long long int> prefiksyx;
    vector<long long int> sufiksyx;
    vector<long long int> odpowiedzi;
    odpowiedzi.resize(n,1e18);
    sort(sasiedzi.begin(),sasiedzi.end(),cmpx);

    prefiksyx.resize(n+1,0);
    prefiksyx[0]=0;
    for(int i=0;i<n-1;i++){
        prefiksyx[i+1]=prefiksyx[i]+abs(sasiedzi[i].x-sasiedzi[i+1].x)*(i+1);
    }
    sufiksyx.resize(n+1,0);
    sufiksyx[0]=0;
    for(int i=0;i<n-1;i++){
        sufiksyx[i+1]=sufiksyx[i]+abs(sasiedzi[n-i-1].x-sasiedzi[n-i-2].x)*(i+1);
    }

    for(int i=0;i<n;i++){
        odpowiedzi[sasiedzi[i].nr]=prefiksyx[i]+sufiksyx[n-1-i];
    }
    

    vector<long long int> prefiksyy;
    vector<long long int> sufiksyy;
    sort(sasiedzi.begin(),sasiedzi.end(),cmpy);

    prefiksyy.resize(n+1,0);
    prefiksyy[0]=0;
    for(int i=0;i<n-1;i++){
        prefiksyy[i+1]=prefiksyy[i]+abs(sasiedzi[i].y-sasiedzi[i+1].y)*(i+1);
    }
    sufiksyy.resize(n+1,0);
    sufiksyy[0]=0;
    for(int i=0;i<n-1;i++){
        sufiksyy[i+1]=sufiksyy[i]+abs(sasiedzi[n-i-1].y-sasiedzi[n-i-2].y)*(i+1);
    }

    for(int i=0;i<n;i++){
        odpowiedzi[sasiedzi[i].nr]=odpowiedzi[sasiedzi[i].nr]+prefiksyy[i]+sufiksyy[n-1-i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<odpowiedzi[i]/2<<" ";
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        long long int x,y;
        cin>>x>>y;x=x*2;y=y*2;
        sasiedzi.push_back({(x+y)/2,(x-y)/2,i});
    }
    wzorcowka(n);
    return 0;
}
 