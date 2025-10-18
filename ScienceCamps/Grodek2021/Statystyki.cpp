#include <iostream>
#include "stalib.h"

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a=init();


    int r=a-1,l=0,wsr,sr,wr;
    wr=getVal(a-1);
    while(l<r)
    {
     sr=(r+l)/2;
     wsr=getVal(sr);
     if(wsr<wr)
    {
        r=sr;
        wr=wsr;
    }
    else
    {
        l=sr+1;
    }
    }
    answer(l,getVal(l));
    return 0;
}