#include <bits/stdc++.h>

using namespace std;
const long long int M=1<<20;
vector<long long int> tree(M<<1);
vector<long long int> tree2(M<<1);
vector<long long int> tree3(M<<1);
vector<long long int> tree4(M<<1);

void add(long long int v,long long int a,long long int b,long long int p,long long int k,long long int x)
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
            long long int l=v*2,r=(v*2)+1,mid=(a+b)/2;
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
long long int suma(long long int v,long long int a,long long int b,long long int p,long long int k)
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
            long long int l=v*2,r=(v*2)+1,mid=(a+b)>>1;
            tree[l]=tree[l]+tree2[v]/2;
            tree[r]=tree[r]+tree2[v]/2;
            tree2[l]=tree2[l]+tree2[v]/2;
            tree2[r]=tree2[r]+tree2[v]/2;
            tree2[v]=0;
            return suma(l,a,mid,p,k)+suma(r,mid+1,b,p,k);
        }
    }
}



void add2(long long int v,long long int a,long long int b,long long int p,int k,long long int x)
{
    if(b<p || k<a)
    {
        return;
    }
    else
    {
        if(p<=a && b<=k)
        {
            tree3[v]=tree3[v]+x;
            tree4[v]=tree4[v]+x;
        }
        else
        {
            long long int l=v*2,r=(v*2)+1,mid=(a+b)>>1;
            tree3[l]=tree3[l]+tree4[v];
            tree3[r]=tree3[r]+tree4[v];
            tree4[l]=tree4[l]+tree4[v];
            tree4[r]=tree4[r]+tree4[v];
            tree4[v]=0;

            add2(l,a,mid,p,k,x);
            add2(r,mid+1,b,p,k,x);

            tree3[v]=min(tree3[l],tree3[r]);
        }
    }
}
long long int minimum(long long int v,long long int a,long long int b,long long int p,long long int k)
{
    if(b<p || k<a)
    {
        return 1e18+9;
    }
    else
    {
        if(p<=a && b<=k)
        {
            return tree3[v];
        }
        else
        {
            long long int l=v<<1,r=(v<<1)+1,mid=(a+b)>>1;
            tree3[l]=tree3[l]+tree4[v];
            tree3[r]=tree3[r]+tree4[v];
            tree4[l]=tree4[l]+tree4[v];
            tree4[r]=tree4[r]+tree4[v];
            tree4[v]=0;
            return min(minimum(l,a,mid,p,k),minimum(r,mid+1,b,p,k));
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d,e;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        cin>>c;
        add(1,0,M-1,i,i,c);
        add2(1,0,M-1,i,i,c);
    }

    for(int i=0;i<b;i++)
    {
        char f;
        cin>>f;
        if(f=='P')
        {
            cin>>c>>d>>e;
            c--;
            d--;
            add(1,0,M-1,c,d,e);
            add2(1,0,M-1,c,d,e);
        }
        if(f=='S')
        {
            cin>>c>>d;
            c--;
            d--;
            cout<<suma(1,0,M-1,c,d)<<endl;
        }
        if(f=='M')
        {
            cin>>c>>d;
            c--;
            d--;
            cout<<minimum(1,0,M-1,c,d)<<endl;
        }
    }
    return 0;
}