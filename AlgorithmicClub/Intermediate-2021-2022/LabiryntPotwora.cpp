#include <iostream>

using namespace std;

int main()
{
    //ilosc testow
    int testy=0;
    cin>>testy;
    //
    for(int i=0;i<testy;i++)
    {
        //wczytywanie danych//
        int dl=0,sz=0,ruchy=0;
        cin>>dl>>sz>>ruchy;
        char tab[ruchy];
        for(int j=0;j<ruchy;j++)
        {
            cin>>tab[j];
        }
        //



    //usuwanie przeszkod przy wejsciu i wyjsciu
    if(tab[0]=='P')
    {
        tab[0]='0';
    }
    if(tab[ruchy-1]=='P')
    {
        tab[ruchy-1]='0';
    }
    //



    //Usuwanie wystajacych elementow w labiryncie
    for(int k=1;k<ruchy;k++)
    {
        if(tab[k]=='0')
        {
            continue;
        }
        else
        {
            if(tab[k]=='P' && tab[k-1]=='P')
            {
                int lewy1=0,lewy2=0;
                while(true)
                {
                    if(tab[(k-1)-lewy1]=='L' && tab[k+lewy2]=='L')
                    {
                        tab[(k-1)-lewy1]='0';
                        tab[k+lewy2]='0';
                        break;
                    }
                    else
                    {
                        if((k-1)-lewy1<0)
                        {
                            tab[k+lewy2]='0';
                            break;
                        }
                        if (k+lewy2>=ruchy)
                        {
                            tab[(k-1)-lewy1]='0';
                            break;
                        }
                    tab[(k-1)-lewy1]='0';
                    tab[k+lewy2]='0';
                    lewy1++;
                    lewy2++;

                    }

                }
            }
        }
    }
    //



    //Odpowiedz
    int nmk=1,is=0,lewy=0;
    for(int m=0;m<ruchy;m++)
    {
        if(tab[m]=='P')
        {
            nmk=0;
            break;
        }
        if(tab[m]=='N')
        {
           is++;
        }
        if(tab[m]=='L')
        {
            lewy++;
        }
    }
    if(nmk=1 && is==(2*dl+2*sz)-1)
    {
        cout<<"NIE"<<endl;
    }
    else
    {
        cout<<"TAK"<<endl;
    }
    //










/*
    //sprawdzenie
    for(int k=0;k<ruchy;k++)
    {
        cout<<tab[k]<<" ";
    }
    cout<<endl<<endl;
    //
*/

    }
    return 0;
}