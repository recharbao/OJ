#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n, m ,x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if(abs(x1 - x2) > 4 || abs(y1 - y2) > 4 || (abs(x1 - x2) >= 4 && abs(y1 - y2) >= 3) || abs(y1 - y2) >= 4 && abs(x1 - x2) >= 3)  cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}

