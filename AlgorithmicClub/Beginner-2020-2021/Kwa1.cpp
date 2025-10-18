#include <iostream>

using namespace std;

int main()
{
    int K;
    cin>>K;
    for (int i=0;i<K;i++)
    {
        for (int j=0;j<K;j++)
        {
            if (i==0 ||i==K-1)
            {
                cout<<"K";
            }
            else
            {
                if (j==0||j==K-1)
                {
                    cout<<"K";
                }
                else
                {
                    cout<<" ";
                }
            }


        }
        cout<<endl;
    }

    return 0;
}