#include <iostream>

using namespace std;
int cunt;
int current;
int get, get2;
int len, stoly;
int main()
{
    cin >> cunt;
    int tab[cunt];
    int holder[cunt];
    for(int i = 0; i < cunt; i++)
    {
        cin >> current;
        tab[i] = current;
    }
    for(int j = 0; j < cunt; j++)
    {
        if(tab[j] != 0)
        {
            get = j;
            for(int i = 0; i < cunt; i++)
            {
                holder[i] = tab[get];
                get2 = get;
                get = holder[i]-1;
            }
            len = 1;
            while(holder[0] != holder[len])
            {
                len++;
            }
            for(int i = 0; i < len; i++)
            {
                tab[holder[i]-1] = 0;
            }
            stoly++;
            for(int i = 0; i < len; i++)
            {
                holder[i] = 0;
            }

        }


    }



    cout << stoly;
}