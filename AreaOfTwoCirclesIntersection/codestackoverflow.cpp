//我的这种解法思路应该是没问题的只是long double都爆掉了，无能为力。
// #include<bits/stdc++.h>
// #include<algorithm>
// #include<cmath>
// # define MY_PI 3.14159265358979323846
// using namespace std;

// typedef long double ld;

// ld pow2(ld x){return x * x;}
// int main()
// {
//     cout.precision(25);
//     ld x1, y1, r1, x2, y2, r2;
//     cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

//     ld c = sqrt(pow2(x2 - x1) + pow2(y2 - y1));
//     if(r1 + r2 <= c)
//     {
//         cout << 0 << endl;
//         return 0;
//     }
//     if((max(r1, r2) - min(r1, r2)) >= c)
//     {
//         cout << MY_PI * pow2(min(r1, r2)) << endl;
//         return 0;
//     }

//     ld x = (pow2(r1) - pow2(r2)) / (2 * c) + c * 0.5;
//     ld y = sqrt(pow2(r1) - pow2(x));
//     ld angle1 = 2.0 * acos(x / r1);
//     ld angle2 = 2.0 * acos((c - x) / r2);
//     ld ar1 = angle1 * pow2(r1) * 0.5;
//     ld ar2 = angle2 * pow2(r2) * 0.5;
//     ld res = ar1 + ar2 - y * c;

//     cout << res << endl;

//     return 0;
// }


/*
0 100000000 1
0 0 100000000
0 0 1000000000
999999998 0 3
*/



#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
typedef long double ld;

struct Circle {
  ld x;
  ld y;
  ld r;
};

static std::istream& operator>>(std::istream& i, Circle& c) {
  return i >> c.x >> c.y >> c.r;
}

static ld Pi() { return std::acos(-1); }

static ld Square(ld x) { return x * x; }

static void SortDescending2(ld& a, ld& b) {
  if (a < b) {
    using std::swap;
    swap(a, b);
  }
}

static void SortDescending3(ld& a, ld& b, ld& c) {
  SortDescending2(a, b);
  SortDescending2(b, c);
  SortDescending2(a, b);
}

static ld KahanAreaOfTriangle(ld a, ld b, ld c) {
  SortDescending3(a, b, c);
  return 0.25 * std::sqrt((a + (b + c)) * (c - (a - b)) * (c + (a - b)) *
                          (a + (b - c)));
}

static ld AreaOfIntersection(const Circle& c1, const Circle& c2) {
  ld R = c1.r;
  ld r = c2.r;
  ld d = std::hypot(c2.x - c1.x, c2.y - c1.y);
  if (R + r <= d) {
    return 0;
  }
  SortDescending2(R, r);
  if (d <= R - r) {
    return Pi() * Square(r);
  }
  ld area = 2 * KahanAreaOfTriangle(R, r, d);
  ld y = area / d;
  ld A = std::asin(y / R) * Square(R);
  ld a = std::asin(y / r);
  if (std::hypot(r, d) <= R) {
    a = Pi() - a;
  }
  a *= Square(r);
  SortDescending2(A, a);
  return (A - area) + a;
}

int main() {
  Circle c1;
  Circle c2;
  if (std::cin >> c1 >> c2) {
    std::cout.precision(std::numeric_limits<ld>::max_digits10);
    std::cout << AreaOfIntersection(c1, c2) << "\n";
  }
}

