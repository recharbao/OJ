#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector<vector<int> > s(n + 1, vector<int>(n, 0));
    int zeroIndex = 0;
    for(int v = n; v >= 1; v--)
    { 
        for(int i = 0; i < n; i++)
        {
            if(v == a[i])
            {   
                for(int j = 0; j < a[i]; j++)
                {
                    s[(zeroIndex + j) % (n + 1)][i] = 1;
                }
                zeroIndex++;
            }
        }
    }


    cout << s.size() << endl;
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << s[i][j];
        }
        cout << endl;
    }


    return 0;
}









/*

10111
11011
11101
11110
11111
01111

41534

00100
10100
10101
10111
11111
00011

*/



