#include <iostream>
#include <stack>

using namespace std;
stack <string> S;


int main()
{
    std::ios_base::sync_with_stdio(0);
    string slowo,wyraz;
    cin>>wyraz;

    for (int i=0;i<wyraz.size();i++)
    {
        if(wyraz[i]!='/')
        {
            slowo=slowo+wyraz[i];
        }
        else
        {
            S.push(slowo);
            slowo.clear();
        }

    }
            if (!slowo.empty())
        {
            S.push(slowo);
            slowo.clear();
        }
    while(!S.empty())
    {
        cout<<S.top();
        S.pop();
        if (!S.empty())
        {
            cout<<"/";
        }
    }
    return 0;
}