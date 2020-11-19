#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int x[n];
    map<int, int> count;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        count[x[i]]++;
    }
    
    int MAX = 0, MIN = 0;

    int pre = -1, wpre = -1;
    int preCenter = -1;

    map<int, int>::iterator iter;

    for (iter = count.begin(); iter != count.end(); iter++, pre = wpre)
    {   
        wpre = min(iter -> first + 1, max(iter -> first - 2, pre) + iter -> second);
        MAX += min(min(iter -> second, 3), wpre - pre);
        
        if((iter -> first - 1) > preCenter)
        {
            preCenter = iter -> first + 1;
            MIN++;
        }
    }

    cout << MIN << " " << MAX << endl;
    
    return 0;
}



/*
9  
1 1 1 4 4 4 2 2 2
*/


/*
10
1 1 1 3 3 3 5 5 5 6
*/
