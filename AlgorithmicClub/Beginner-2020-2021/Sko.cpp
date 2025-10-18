#include <iostream>

using namespace std;

int main()
{
    bool tab1[101][101][101];
    std::ios_base::sync_with_stdio(0);
    int rk,it,a,b,c,a1,b1,c1,wynik=0;
    cin>>rk>>it;

for (int k=1;k<rk+1;k++)
{
     for (int i=1;i<rk+1;i++)
    {
        for (int j=1;j<rk+1;j++)
        {
            cin>>tab1[k][i][j];
        }
    }
}






                                                             /* for (int k=1;k<rk+1;k++)
                                                            {
                                                             for (int i=1;i<rk+1;i++)
                                                           {
                                                               for (int j=1;j<rk+1;j++)
                                                            {
                                                              cout<<tab1[k][i][j]<<" ";
                                                             }
                                                            cout<<endl;
                                                           }
                                                              }*/


                                                             //cout<<rk<<" "<<it;
                                                           /*for (int i=1;i<rk*rk+1;i++)
                                                             {
                                                             for (int j=1;j<rk+1;j++)
                                                             {
                                                              cout<<tab1[i][j]<<" ";
                                                             }
                                                             cout<<endl;
                                                             }*/


    for (int i=0;i<it;i++)
    {
        wynik=0;
        cin>>a>>b>>c;
        cin>>a1>>b1>>c1;
                                                              //cout<<a<<" "<<b<<" "<<c<<" ";
                                                             //cout<<a1<<" "<<b1<<" "<<c1<<" ";
        for (int j=c;j<=c1;j++)
        {
            //cout<<1<<endl;
            for (int k=b;k<=b1;k++)
            {
                //cout<<1<<endl;
                for (int o=a;o<=a1;o++)
                {

                    //cout<<1<<endl;
                    if(tab1[j][k][o]!=0)
                    {
                                                            //cout<<j<<" "<<k<<" "<<o<<" ";
                        wynik++;
                                                           //  cout<<endl;
                    }
                }
            }
        }



        cout<<wynik<<endl;
    }



    return 0;
}