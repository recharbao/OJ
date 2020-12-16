#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

# define MY_PI 3.14159265358979323846

int main()
{
    double W, H, a;
    cin >> W >> H >> a;

    if(W < H) swap(W, H);
    if(a > 90) a = 180 - a;
    a = (a / 180) * MY_PI;

    double p = (W * W - H * H) / (2 * W);
    cout.precision(25);
    if(tan(a) > H / p)
    {
        cout << (H * H) / sin(a) << endl;
        return 0;
    }

    double h = H * cos(a);
    double w = W * cos(a);

    double s = sin(a);
    double t = cos(a);

    double y = (h * (1 + t) - s * w) / (((1 + t) * (1 + t) - s * s) * t);
    double x = w / (1 + t) - (s * t) / (1 + t) * y;

    cout << W * H -  x * x * tan(a) -  y * y * s * t << endl;

    return 0;
}
