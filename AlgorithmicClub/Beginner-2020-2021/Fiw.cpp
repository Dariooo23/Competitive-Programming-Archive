#include <iostream>
#include <vector>
using namespace std;

struct Vector
{
    int x,y;
    Vector(pair<int,int> a, pair<int,int>b)
    {
        x=b.first-a.first;
        y=b.second-a.second;
    }
};
int vectorProduct(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> points (n);
    for (int i=0;i<n;i++)
    {
        cin>>points[i].first>>points[i].second;

    }
    int plusy=0,minusy=0;
    for (int i=0;i<n;i++)
    {
        pair<int, int> & p0=points[i];
        pair<int, int> & p1=points[(i+1)%n];
        pair<int, int> & p2=points[(i+2)%n];
        int ccw=vectorProduct({p0,p1},{p0,p2});
        if (ccw>=0)
        {
            plusy++;

        }
        if (ccw<=0)
        {
            minusy++;
        }
    }
    if (plusy==n||minusy==n)
    {
        cout<<"TAK"<<endl;
    }
    else
    {
        cout<<"NIE"<<endl;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    int a;
    cin>>a;
    while (a--)
    {
        solve();
    }
    return 0;
}