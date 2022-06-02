#include<bits/stdc++.h>
#include<map>
#include<algorithm>
#include<vector>
#include<string.h>
#include<numeric>
using namespace std;
typedef long long ll;

struct P {
    int a;
    int b;
    int id;
}p[200010];

bool cmp (P p1, P p2) {
    return p1.a < p2.a;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int N;
        cin >> N;
        for (int i = 1; i <= 2 * N - 1; i++) {
            int x, y;
            cin >> p[i].a >> p[i].b;
            p[i].id = i;
        }
        sort(p + 1, p + 2 * N, cmp);

        cout << "YES" << endl;

        for (int i = 1; i < 2 * N - 1; i += 2) {
            if (p[i].b > p[i + 1].b) {
                cout << p[i].id << " ";
            }else {
                cout << p[i + 1].id << " ";
            }
        }
        cout << p[2 * N - 1].id << endl;
    }
        
    return 0;
}





// 1
// 4
// 1 7
// 1 6
// 1 5
// 1 4
// 5 3
// 6 2
// 7 1
