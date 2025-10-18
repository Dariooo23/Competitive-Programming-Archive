#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


 char reverseLetter(char c)
 {
     if (islower(c))
     {
         return (char)toupper(c);

     }
     else
     {
         return (char)tolower(c);
     }
 }
int main()
{
    string s;
    getline(cin,s);
    for (int i=0;i<(int)s.size();i++)
    {
        switch (s[i])
        {
        case ' ':
            break;
        case '#':
            cout<<" #";
            break;
        case  '-':
            cout<<"+";
            break;
        default:
            if (isalpha(s[i]))
            {
                cout<<reverseLetter(s[i]);

            }
            else
            {
                cout<<s[i];
            }

        }
    }
    return 0;
}