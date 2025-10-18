#include <iostream>

using namespace std;

int rodzic[10000000];
int fin(int x)
{
    if(rodzic[x]==x) return x;
    else return rodzic[x]= fin(rodzic [x]);
}
void unio(int x, int y)
{
    int rodzicX=fin(x);
    int rodzicY=fin(y);
    if(rodzicX!=rodzicY) rodzic[rodzicX]=rodzicY;
}






struct Point
{
    long long x,y;
    Point(long long _x=0, long long _y=0)
    {
        x=_x;
        y=_y;
    }
};
struct Vector
{
    long long x,y;
    Vector(Point A, Point B)
    {
        x=B.x-A.x;
        y=B.y-A.y;
    }
};





long long vectorProduct(Vector A, Vector B)
{
    return A.x*B.y-A.y*B.x;
}
bool onSegment(Point A, Point B, Point C)
{
    return min(A.x,B.x)<= C.x && C.x <=max(A.x,B.x)
    && min(A.y,B.y)<= C.y && C.y <=max(A.y,B.y);
}
bool segmentIntersect(Point A, Point B, Point C, Point D)
{
    long long iABC= vectorProduct(Vector(A,B), Vector(A,C));
    long long iABD= vectorProduct(Vector(A,B), Vector(A,D));
    long long iCDA= vectorProduct(Vector(C,D), Vector(C,A));
    long long iCDB= vectorProduct(Vector(C,D), Vector(C,B));

    if(iABC*iABD<0 && iCDA* iCDB<0)
    {
        return true;
    }
    if(iABC==0 && onSegment(A,B,C))
    {
        return true;
    }
    if(iABD==0 && onSegment(A,B,D))
    {
        return true;
    }if(iCDA==0 && onSegment(C,D,A))
    {
        return true;
    }if(iCDB==0 && onSegment(C,D,B))
    {
        return true;
    }
    return false;
}







int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,b,c;
    cin>>a;
    int tab[a][4];
    for(int i=0;i<a;i++)
    {
         rodzic[i]=i;
    }
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<4;j++)
        {
            cin>>tab[i][j];
        }
    }
     /*for (int i=0;i<a;i++)
    {
        for (int j=0;j<4;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }*/



         /* int cos;
            Point A,B,C,D;
            A.x=tab[0][0];
             A.y=tab[0][1];
            B.x=tab[0][2];
             B.y=tab[0][3];
            C.x=tab[2][0];
             C.y=tab[2][1];
            D.x=tab[2][2];
             D.y=tab[2][3];
            cos=segmentIntersect(A,B,C,D);
          if (cos==true)
          {
             cout<<"TAK";
          }
          else
          {
              cout<<"NIE";
          }*/








     for (int i=0;i<a;i++)
    {
        for (int j=0;j<a;j++)
        {
            int cos;
            Point A,B,C,D;
            A.x=tab[i][0];
             A.y=tab[i][1];
            B.x=tab[i][2];
             B.y=tab[i][3];
            C.x=tab[j][0];
             C.y=tab[j][1];
            D.x=tab[j][2];
             D.y=tab[j][3];
            cos=segmentIntersect(A,B,C,D);
          if (cos==true)
          {
              unio(i,j);
          }
        }
    }





    while (cin>>b)
    {
        cin>>c;
        if (b==0 &&c==0)
        {
            break;
        }
        b=b-1;
        c=c-1;
        if(fin(b)==fin(c)) cout<<"TAK"<<endl;
            else cout<<"NIE"<<endl;

    }

    return 0;
}