#include <bits/stdc++.h>

using namespace std;

const int M=1<<20;
int licz=1;
vector<int> ood(2*M+1);
vector<int> doo(2*M+1);
vector<long long int> tree(2*M+1);
vector<long long int> tree2(2*M+1);
vector<int> wejscie(2*M+1);
vector<vector<int>> g;


void start(int a,int b,int indeks)
{
    if(a==b)
    {
        tree[indeks]=wejscie[a];
    }
    else
    {
       int mid=((a+b)>>1);
       start(a,mid,indeks<<1);
       start(mid+1,b,(indeks<<1)+1);
       tree[indeks]=tree[indeks<<1]+tree[(indeks<<1)+1];
    }
}


void add(int v,int a,int b,int p,int k,long long int x)
{
    if(b<p || k<a)
    {
        return;
    }
    else
    {
        if(p<=a && b<=k)
        {
            tree[v]=tree[v]+(b-a+1)*x;
            tree2[v]=tree2[v]+(b-a+1)*x;
        }
        else
        {
            int l=v<<1,r=(v<<1)+1,mid=(a+b)>>1;
            tree[l]=tree[l]+tree2[v]/2;
            tree[r]=tree[r]+tree2[v]/2;
            tree2[l]=tree2[l]+tree2[v]/2;
            tree2[r]=tree2[r]+tree2[v]/2;
            tree2[v]=0;

            add(l,a,mid,p,k,x);
            add(r,mid+1,b,p,k,x);

            tree[v]=tree[l]+tree[r];
        }
    }
}


long long int suma(int v,int a,int b,int p,long long int k)
{
    if(b<p || k<a)
    {
        return 0;
    }
    else
    {
        if(p<=a && b<=k)
        {
            return tree[v];
        }
        else
        {
            int l=v<<1,r=(v<<1)+1,mid=(a+b)>>1;
            tree[l]=tree[l]+tree2[v]/2;
            tree[r]=tree[r]+tree2[v]/2;
            tree2[l]=tree2[l]+tree2[v]/2;
            tree2[r]=tree2[r]+tree2[v]/2;
            tree2[v]=0;
            return suma(l,a,mid,p,k)+suma(r,mid+1,b,p,k);
        }
    }
}


int dfs(int s,int p)
{
    ood[s]=1;
    doo[s]=licz++;
    for(int v:g[s])
    {
        if(v!=p)
        {
            ood[s]=ood[s]+dfs(v,s);
        }
    }
    return ood[s];
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n,m,a,b,c;
    cin>>n>>m;
    g.resize(n+9);
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        g[a].push_back(i);
    }


    for(int i=0;i<g[0].size();i++)
    {
        dfs(g[0][i],0);
    }


    for(int i=1;i<=n;i++)
    {
        cin>>wejscie[doo[i]];
    }
    start(1,M,1);


    for(int i=0;i<m;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            add(1,1,M,doo[b],doo[b]+ood[b]-1,c);
        }
        if(a==2)
        {
            cin>>b>>c;
            //cout<<suma(1,1,M,doo[b],doo[b]+ood[b]-1)<<endl;
            if(suma(1,1,M,doo[b],doo[b]+ood[b]-1)<c)
            {
                cout<<"TAK\n";
            }
            else
            {
                cout<<"NIE\n";
            }
        }
    }
    return 0;
}