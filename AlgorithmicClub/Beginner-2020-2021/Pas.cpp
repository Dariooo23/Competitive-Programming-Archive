#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n=5000;
    int a,k,b;

    long long **trojkatPascala;
  trojkatPascala= new long long *[n];
  for (int j=0;j<n;j++)
  {
      trojkatPascala[j]=new long long [j+1];
      trojkatPascala[j][0]=1;
      trojkatPascala[j][j]=1;

      for (int i=0; i<j-1; i++)
      {
          trojkatPascala[j][i+1]=trojkatPascala[j-1][i]+trojkatPascala[j-1][i+1];
      }
  }

    cin>>b;

    for (int i=0;i<b;i++)
    {
        cin>>a>>k;

        if (trojkatPascala[a][k]%2==0)
        {
            cout<<"P"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }

    }

    return 0;
}