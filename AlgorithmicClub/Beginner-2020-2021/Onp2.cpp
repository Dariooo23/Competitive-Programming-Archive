#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    string line;
    getline(cin,line);
    stack<string> onpStack;
    string lastVariable;
    for (char c: line)
    {
        if (isalnum(c))
        {
            lastVariable+=c;
        }
        else
        {
            if (!lastVariable.empty())
            {
                onpStack.push(lastVariable);
                lastVariable="";
            }
            if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%')
            {
                string b=onpStack.top();
                onpStack.pop();
                string a=onpStack.top();
                onpStack.pop();
                onpStack.push("("+a+c+b+")");
            }

        }
    }
    string top=onpStack.top();
    int len=(int)top.size()-2;
    string result=top.substr(1,len);
    cout<<result<<endl;

}
int main()
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}