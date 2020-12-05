#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n, m, i, j, a , b;
    int MINval = INT32_MAX;
    cin >> n >> m >> i >> j >> a >> b;


    if(i == 1 && j == 1 || i == 1 && j== m || i == n && j == 1 || i == n && j == m) MINval = 0;
    if((((i - 1) / a + (j - 1) / b) % 2 == 0 && (i - 1) % a == 0 && (j - 1) % b == 0) && (max((i - 1) / a, (j - 1) / b) < MINval) && (((i + a) <= n && (j - b) >= 1) || ((i - a) >= 1 && (j + b) <= m || ((i - a) >= 1 && (j - b) >= 1)))) MINval = max((i - 1) / a, (j - 1) / b);
    if((((i - 1) / a + (m - j) / b) % 2 == 0 && (i - 1) % a == 0 && (m - j) % b == 0) && (max((i - 1) / a, (m - j) / b) < MINval) && (((i + a) <= n && (j + b) <= m) || ((i - a) >= 1 && (j + b) <= m || ((i - a) >= 1 && (j - b) >= 1)))) MINval = max((i - 1) / a, (m - j) / b);
    if((((n - i) / a + (j - 1) / b) % 2 == 0 && (n - i) % a == 0 && (j - 1) % b == 0) && (max((n - i) / a, (j - 1) / b) < MINval) && (((i + a) <= n && (j + b) <= m) || ((i + a) <= n && (j - b) >= 1 || ((i - a) >= 1 && (j - b) >= 1)))) MINval = max((n - i) / a, (j - 1) / b);
    if((((n - i) / a + (m - j) / b) % 2 == 0 && (n - i) % a == 0 && (m - j) % b == 0) && (max((n - i) / a, (m - j) / b) < MINval) && (((i + a) <= n && (j + b) <= m) || ((i + a) <= n && (j - b) >= 1 || ((i - a) >= 1 && (j + b) <= m)))) MINval = max((n - i) / a, (m - j) / b);

    if(MINval == INT32_MAX) cout << "Poor Inna and pony!" << endl;
    else cout << MINval << endl;
    
    return 0;
}

/*



*/

