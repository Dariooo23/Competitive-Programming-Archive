#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
int a,b;
cin>>a;
for (int i=0;i<a;i++)
{
    cin>>b;
    int c[b];
    for (int j=0;j<b;j++)
    {
        cin>>c[j];
    }
    for (int k=0;k<b-1;k++)
    {
        cout<<c[k+1]<<" ";
    }
    cout<<c[0]<<" "<<endl;


}
    return 0;
}