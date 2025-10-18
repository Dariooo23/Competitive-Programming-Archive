#include <bits/stdc++.h>

using namespace std;

struct Point{
long long x,y;
};
void solve(){
int n;
cin>>n;
vector<Point>points;
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    points.push_back({x,y});
}
sort(points.begin(),points.end(),[](Point a,Point b){
     long long vectorProduct=a.x*b.y-a.y*b.x;
     if(vectorProduct==0){
        return a.x+a.y<b.x+b.y;
     }
     return vectorProduct<0;
     });
     for(Point p: points){
        cout<<p.x<<" "<<p.y<<endl;
     }
}
int main()
{
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}