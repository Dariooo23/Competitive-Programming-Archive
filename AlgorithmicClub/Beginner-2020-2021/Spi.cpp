#include <iostream>

using namespace std;

int main()
{
    char WZ;
    int wynik=0,iu=0,wcz;
    cin>>wcz;
    for (int i=0;i<wcz;i++)
    {
        cin>>WZ;
         if (WZ=='W')
        {
            iu=0;
        }
        if (WZ=='Z')
        {
            iu++;
        }
        if (iu==1)
        {
            wynik++;
        }
        if (iu==3)
        {

            iu=0;
        }

    }
    cout<<wynik;
    return 0;
}