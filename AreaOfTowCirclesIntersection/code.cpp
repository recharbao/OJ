#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
# define MY_PI 3.14159265358979323846
using namespace std;

typedef long double ld;

ld pow2(ld x){return x * x;}
int main()
{
    cout.precision(25);
    ld x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ld c = sqrt(pow2(x2 - x1) + pow2(y2 - y1));
    if(r1 + r2 < c)
    {
        cout << 0 << endl;
        return 0;
    }
    if((max(r1, r2) - min(r1, r2)) >= c)
    {
        cout << MY_PI * pow2(min(r1, r2)) << endl;
        return 0;
    }

    ld x = (pow2(r1) - pow2(r2)) / (2 * c) + c * 0.5;
    ld y = sqrt(pow2(r1) - pow2(x));
    ld angle1 = 2.0 * acos(x / r1);
    ld angle2 = 2.0 * acos((c - x) / r2);
    ld ar1 = angle1 * pow2(r1) * 0.5;
    ld ar2 = angle2 * pow2(r2) * 0.5;
    ld res = ar1 + ar2 - y * c;

    cout << res << endl;

    return 0;
}






/*
0 100000000 1
0 0 100000000

0 0 1000000000
999999998 0 3

*/
