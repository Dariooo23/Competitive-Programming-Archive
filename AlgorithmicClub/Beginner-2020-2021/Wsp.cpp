#include <iostream>

using namespace std;
int dsa (int a1,int a2,int b1,int b2)
{
    int c=a1*b2-a2*b1;

    if(c==0) return 0;
    else return 1;
}
int main()
{
int a1,a2,b1,b2,c1,c2,n;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a1>>a2>>b1>>b2>>c1>>c2;
    if(dsa(b1-a1,b2-a2,c1-b1,c2-b2)==0) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;

}
}