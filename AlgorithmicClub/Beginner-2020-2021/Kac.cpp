#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    queue<int> Q;
    Q.push(n);
    for (int i=n-1;i>=1;i--)
    {
        int a=Q.front();
        Q.pop();
        Q.push(a);
        Q.push(i);
    }
    vector <int> V;
    while(!Q.empty())
    {
        V.push_back(Q.front());
        Q.pop();
    }
    reverse(V.begin(),V.end());
    for(int x : V)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}


int main()
{
   int a;
   cin>>a;
   for (int i=0;i<a;i++)
   {
       solve();
   }

    return 0;
}