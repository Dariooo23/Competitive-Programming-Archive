#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int>size(n),direction(n);
    for (int i=0;i<n;i++)
    {
        cin>>size[i];
    }
    for (int i=0;i<n;i++)
    {
        cin>>direction[i];
    }
    int result=0;
    stack<int> S;
    for (int i=0;i<n;i++)
    {
        if (direction[i]==0)
        {
            while(!S.empty() && S.top()<size[i])
            {
                S.pop();
            }
            if (S.empty())
            {
                result++;
            }
        }
        else
        {
           S.push(size[i]);
        }
    }
    result+=(int)S.size();
    cout<<result<<endl;
}
int main()
{
    solve();
    return 0;
}