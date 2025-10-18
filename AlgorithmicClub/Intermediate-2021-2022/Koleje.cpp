//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int M=1<<16;
vector<long long int> tree(M<<1);
vector<long long int> tree2(M<<1);

void add(int v,int a,int b,int p,int k,int x)
{
    if(b<p || k<a)
    {
        return;
    }
    else
    {
        if(p<=a && b<=k)
        {
            tree[v]=tree[v]+x;
            tree2[v]=tree2[v]+x;
        }
        else
        {
            long long int l=v<<1,r=(v<<1)+1,mid=(a+b)>>1;
            tree[l]=tree[l]+tree2[v];
            tree[r]=tree[r]+tree2[v];
            tree2[l]=tree2[l]+tree2[v];
            tree2[r]=tree2[r]+tree2[v];
            tree2[v]=0;

            add(l,a,mid,p,k,x);
            add(r,mid+1,b,p,k,x);

            tree[v]=max(tree[l],tree[r]);
        }
    }
}

long long int suma(int v,int a,int b,int p,int k)
{
    if(b<p || k<a)
    {
        return -1e18;
    }
    else
    {
        if(p<=a && b<=k)
        {
            return tree[v];
        }
        else
        {
            long long int l=v<<1,r=(v<<1)+1,mid=(a+b)>>1;
            tree[l]=tree[l]+tree2[v];
            tree[r]=tree[r]+tree2[v];
            tree2[l]=tree2[l]+tree2[v];
            tree2[r]=tree2[r]+tree2[v];
            tree2[v]=0;
            return max(suma(l,a,mid,p,k),suma(r,mid+1,b,p,k));
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,z;
    cin>>n>>m>>z;

    for(int i=0;i<z;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(suma(1,1,M,a,b-1)+c>m)
        {
            cout<<"N"<<'\n';
        }
        else
        {
            add(1,1,M,a,b-1,c);
            cout<<"T"<<'\n';
        }
    }
    
    return 0;
}