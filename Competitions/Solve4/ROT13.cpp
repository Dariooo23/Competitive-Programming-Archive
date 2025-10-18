//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string tekst;
    cin>>tekst;

    for(int i=0;i<tekst.size();i++){
        if(tekst[i]>='0' && tekst[i]<='9'){
            cout<<tekst[i];
        }else{
            if(tekst[i]>='a' && tekst[i]<='z'){
                if((char)(tekst[i]-13)>='a'){
                    cout<<(char)(tekst[i]-13);
                }else{
                    cout<<(char)(tekst[i]+13);
                }
            }else{
                if(tekst[i]>='A' && tekst[i]<='Z'){
                    if((char)(tekst[i]-13)>='A'){
                        cout<<(char)(tekst[i]-13);
                    }else{
                        cout<<(char)(tekst[i]+13);                        
                    }
                }   
            }
        }
    }
    return 0;
}