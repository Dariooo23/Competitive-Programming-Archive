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
    if (b==0)cout<<"0 1"<<endl;
    if (b==1)cout<<"0 1"<<endl;
    if (b==2)cout<<"0 2"<<endl;
    if (b==3)cout<<"0 6"<<endl;
    if (b==4)cout<<"2 4"<<endl;
    if (b==5)cout<<"2 0"<<endl;
    if (b==6)cout<<"2 0"<<endl;
    if (b==7)cout<<"4 0"<<endl;
    if (b==8)cout<<"2 0"<<endl;
    if (b==9)cout<<"8 0"<<endl;
    if (b>=10)cout<<"0 0"<<endl;

}
    return 0;
}