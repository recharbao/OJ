#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int res = 0, manFront = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'M')
        {
            manFront++;
        }
        if(s[i] == 'F' && manFront > 0)
        {
            res = max(res + 1, manFront); //这一步solution有解释
        }
    }

    cout << res << endl;

    return 0;
}





//以下错误的一个思路，以及反例


/*
int main()
{
    string s;
    cin >> s;
    int count = 0;
    if (s.find_first_of('F') > s.size())
    {
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = s.find_first_of('M'); i <= s.find_last_of('F'); i++)
    {
        if(s[i] == 'M')
        {
            count++;
        }
        else if(i > 0 && s[i] == 'F' && s[i - 1] == 'F')
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
*/


/*

MFFMMF
MFFFFMF


*/
