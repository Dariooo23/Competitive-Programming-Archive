#include <iostream>

using namespace std;

int main()
{
 float Nad1, Nad2, U1, U2,wejscie;

 int K1, K2, Pod1, Pod2, Hajs;
double  Sred;
 cin>>wejscie;
 while(wejscie>0)
 {
     cin>>Pod1>>Pod2>>Hajs;

     Pod1=Pod1*3;
     Pod2=Pod2*3;
     Sred=Pod1+Pod2;
     Sred=Sred/3;
     Nad1=Pod1-Sred;
     Nad2=Pod2-Sred;
     U1=Nad1/Sred;
     U2=Nad2/Sred;
     U1=U1*Hajs;
     U2=U2*Hajs;
     K1=U1;
     K2=U2;

     cout<<K1<<" "<<K2<<endl;
     wejscie--;
 }

}