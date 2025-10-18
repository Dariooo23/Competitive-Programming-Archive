//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    cin>>slowo;

    cout<<"+";
    for(int i=0;i<slowo.size()+2;i++){
        cout<<"-";
    }
    cout<<"+";
    cout<<endl;
    cout<<"|";
    for(int i=0;i<slowo.size()+2;i++){
        cout<<" ";
    }
    cout<<"|";
    cout<<endl;
    cout<<"| ";
    cout<<slowo;
    cout<<" |";
    cout<<endl;
    cout<<"|";
    for(int i=0;i<slowo.size()+2;i++){
        cout<<" ";
    }
    cout<<"|";
    cout<<endl;
    cout<<"+";
    for(int i=0;i<slowo.size()+2;i++){
        cout<<"-";
    }
    cout<<"+";
    cout<<endl;


    return 0;
}