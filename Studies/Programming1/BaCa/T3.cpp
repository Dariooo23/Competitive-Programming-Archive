//Karol Dziekan
#include <iostream>

using namespace std;

int main(){
    int zestawy=0;
    int dane=0;

    float minimum=0;
    float maksimum=0;
    float srednia=0;
    float rzeczywista=0;

    cin>>zestawy;
    
    while(zestawy>0){
        zestawy=zestawy-1;

        cin>>rzeczywista;
        
        minimum=rzeczywista;
        maksimum=rzeczywista;
        srednia=rzeczywista;

        dane=4;
        while(dane>0){
            dane=dane-1;
            cin>>rzeczywista;

            if(rzeczywista<minimum)
                minimum=rzeczywista;
            if(rzeczywista>maksimum)
                maksimum=rzeczywista;
            srednia=srednia+rzeczywista;
        }

        cout<<minimum<<" "<<maksimum<<" "<<srednia/5<<endl;
    }
    
    return 0;
}