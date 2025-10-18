#include <iostream>
using namespace std;

void dnd(int liczba)
{
	int i=0,tab[31];

	while(liczba)
	{
		tab[i++]=liczba%2;
		liczba/=2;
	}
    for (int k=0;k<16-i;k++)
    {
        cout<<0;
    }
	for(int j=i-1;j>=0;j--)
		cout<<tab[j];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
	int liczba;
	while (cin>>liczba)
    {
        dnd(liczba);
	cout<<endl;
    }

	return 0;
}