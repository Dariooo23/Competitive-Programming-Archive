#include <iostream>
#include "guelib.h"
using namespace std;

int main()
{
    int n=init();
    int l=0,r=n,sr=0;
    while(l<r)
    {
        sr=(l+r)/2;
        if(isGreater(sr))
        {
            l=sr+1;
        }
        else
        {
            r=sr;
        }
    }
    answer(l);

    return 0;
}