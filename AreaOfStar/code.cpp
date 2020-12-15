#include<iostream>
#include<math.h>
using namespace std;
# define MY_PI 3.14159265358979323846


int main()
{
    int n, r;
    cin >> n >> r;

    cout.precision(25);
    cout << (n * pow(r, 2)) / (1.0 / tan(MY_PI / (2 * n)) + 1.0 / tan(MY_PI / n)) << endl;
    
    return 0;
}
