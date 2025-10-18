//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;
    vector<long long int> wejscie(n);
    vector<long long int> wejscie2(n);
    for(int i=0;i<n;i++){
        cin>>wejscie[i];
        wejscie2[i]=wejscie[i];
    }

    sort(wejscie2.begin(),wejscie2.end());

    int pozycja1=-1,pozycja2=-1;
    for(int i=0;i<n;i++){
        if(wejscie[i]!=wejscie2[i]){
            if(pozycja1==-1){
                pozycja1=i;
            }else{
                if(pozycja2==-1){
                    pozycja2=i;
                }else{
                    cout<<"NIE";
                    return 0;
                }
            }
        }
    }

    if(pozycja1==-1){
        cout<<"TAK";
        return 0;
    }else{
        cout<<"NAPRAWA"<<endl;
        cout<<pozycja1+1<<" "<<pozycja2+1;
    }

   
    return 0;
}