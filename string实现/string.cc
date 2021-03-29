#include "string.h"

 
int main()
{
    
    string s1 = "hello world";
    string s2 = s1;

    s1 += '!';

    s2 += "! hello bit!"

   // for(int i = 0; s1[i]; i++)
   // {
   //     cout << s1[i] ;
   // }
   // cout << endl;
    
    for(int i = 0; s2[i]; i++)
    {
        cout << s2[i] ;
    }
    cout << endl;

    return 0;
}
