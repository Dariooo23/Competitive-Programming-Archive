//Karol Dziekan
#include <iostream>

using namespace std;

int main(){
    int ilosc=0;
    int identyfikator=0;
    int cwiczenia=0;
    int baca=0;
    int suma=0;

    cin>>ilosc;
    
    while(ilosc>0){
        ilosc=ilosc-1;

        cin>>identyfikator>>cwiczenia>>baca;

        suma=cwiczenia+baca;

        cout<<identyfikator<<" "<<suma<<"% ";

        if(suma<50){
            cout<<"niedostateczny (2.0)"<<endl;
        }else{
            if(suma<60){
                cout<<"dostateczny (3.0)"<<endl;
            }else{
                if(suma<70){
                    cout<<"dostateczny plus (3.5)"<<endl;
                }else{
                    if(suma<80){
                        cout<<"dobry (4.0)"<<endl;
                    }else{
                        if(suma<90){
                            cout<<"dobry plus (4.5)"<<endl;
                        }else{
                            cout<<"bardzo dobry (5.0)"<<endl;
                        }
                    }
                }
            }  
        }
    }
    
    return 0;
}