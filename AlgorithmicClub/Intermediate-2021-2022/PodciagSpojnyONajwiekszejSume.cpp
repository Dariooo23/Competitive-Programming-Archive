#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a;
    int sum=0,sum_now=0;
    cin>>a;
    int t[a];
    for (int i=0;i<a;i++)
    {
        cin>>t[i];
    }

    for (int i = 0; i < a; i++)
    {
         if(sum_now+t[i]>=0)
        {
            sum_now += t[i];
        }
		else
        {
           sum_now = 0;
        }

		sum = max(sum_now, sum);
	}
	cout<<sum;
    return 0;
}