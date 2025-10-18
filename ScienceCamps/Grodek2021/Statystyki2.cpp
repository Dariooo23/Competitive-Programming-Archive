#include <iostream>
#include "stalib.h"
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a=init(),szukana=getTarget();
    int l=0,r=a-1,mid,dziala=0, RVal=getVal(r);
    while(l<=r)
    {
        mid=(l+r)/2;
        int MidVal=getVal(mid);
        if(MidVal==szukana)
        {
            answer(mid);
            return 0;
        }
       if(RVal==szukana)
        {
            answer(r);
            return 0;
        }

    if(szukana<=RVal)
    {
        if(MidVal>RVal)
        {
            l=mid+1;

        }
        else
        {
            if(MidVal>szukana)
            {
                r=mid-1;

            }
            else
            {
                l=mid+1;

            }
        }
    }
    else
    {
        if(MidVal<=RVal)
        {
            r=mid-1;

        }
        else
        {
            if(MidVal>szukana)
            {
                r=mid-1;

            }
            else
            {
                l=mid+1;

            }
        }
    }
    }


    answer(-1);
    return 0;
}
Dz