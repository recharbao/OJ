#include<bits/stdc++.h>
#include<map>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;

int main() {
    ll a1, b1, a2, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    
    L = max(L, max(b1, b2));
    if(L > R) {
        cout << 0 << endl;
        return 0;
    }

    b1 %= a1;
    b2 %= a2;

    ll m = (a1 * a2) / __gcd(a1, a2);
    ll b = b2 - b1;

    ll k1 = 0, k2 = 0;
    if(b != 0) {
        for(int i = 1; i < 2300000; i++) {
            ll mm = i * m;
            ll aa1 = mm / a1;
            ll aa2 = mm / a2;
            if((aa2 - b) % a2 != 0) {
                continue;
            }else {
                k1 = aa1 / a2;
                k2 = (aa2 - b) / a2;
                break;
            }
        }
    }

    if((k1 * a1 + b1 != k2 * a2 + b2) && (b % max(a1, a2) != 0)) {
        cout << 0 << endl;
        return 0;
    }

    ll base = min(k1 * a1 + b1 - (abs(L / m) + abs(base / m) + 2) * m, k2 * a2 + b2 - (abs(L / m) + abs(base / m) + 2) * m);
    ll count = ((R - base) / m) - ((L - base) / m)  + (((L - base) % m) == 0 ? 1 : 0);
    
    cout << count << endl;
}



























// #include<bits/stdc++.h>
// #include<map>
// #include<algorithm>
// #include<vector>
// #include<math.h>
// using namespace std;
// typedef long long ll;

// int main() {
//     ll a1, b1, a2, b2, L, R;
//     cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    
//     L = max(L, max(b1, b2));
//     if(L > R) {
//         cout << 0 << endl;
//         return 0;
//     }

//     b1 %= a1;
//     b2 %= a2;

//     ll m = (a1 * a2) / __gcd(a1, a2);
//     ll b = b2 - b1;

//     ll k1 = 0, k2 = 0;
//     if(b != 0) {
//         for(int i = 1; i < 10000000; i++) {
//             ll mm = i * m;
//             ll aa1 = mm / a1;
//             ll aa2 = mm / a2;
//             if((aa2 - b) % a2 != 0) {
//                 continue;
//             }else {
//                 k1 = aa1 / a2;
//                 k2 = (aa2 - b) / a2;
//                 break;
//             }
//         }
//     }

//     if(k1 * a1 + b1 != k2 * a2 + b2) {
//         if(b % max(a1, a2) != 0) {
//             cout << 0 << endl;
//             return 0;
//         }
//     }

//     ll base = min(k1 * a1 + b1 - (abs(L / m) + abs(base / m) + 2) * m, k2 * a2 + b2 - (abs(L / m) + abs(base / m) + 2) * m);
//     ll count = ((R - base) / m) - ((L - base) / m)  + (((L - base) % m) == 0 ? 1 : 0);
//     cout << count << endl;
// }























// #include<bits/stdc++.h>
// #include<map>
// #include<algorithm>
// #include<vector>
// #include<math.h>
// using namespace std;
// typedef long long ll;

// int main() {
//     ll a1, b1, a2, b2, L, R;
//     cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
//     L = max(L, max(b1, b2));
//     if(L > R) {
//         cout << 0 << endl;
//         return 0;
//     }

//     b1 %= a1;
//     b2 %= a2;

//     // b1 = (b1 + a1) % a1;
//     // b2 = (b2 + a2) % a2;

//     ll m = (a1 * a2) / __gcd(a1, a2);

//     ll b = b2 - b1;
    


//     ll k1 = 0, k2 = 0;
//     if(b != 0) {
//         for(int i = 1; i < 10000000; i++) {
//             ll mm = i * m;
//             ll aa1 = mm / a1;
//             ll aa2 = mm / a2;
//             if((aa2 - b) % a2 != 0) {
//                 continue;
//             }else {
//                 k1 = aa1 / a2;
//                 k2 = (aa2 - b) / a2;
//                 // cout << "i = " << i << " aa2 = " << aa2 << " b = " << b << endl;
//                 break;
//             }
//         }
//     }

//     // cout << "k1 = " << k1 << "   " << "k2 = " << k2 << endl;
//     // cout << "base1 = " << k1 * a1 + b1 << endl;
//     // cout << "base2 = " << k2 * a2 + b2 << endl;

//     if(k1 * a1 + b1 != k2 * a2 + b2) {
//         if(b % max(a1, a2) != 0) {
//             cout << 0 << endl;
//             return 0;
//         }
//     }

//     ll base = min(k1 * a1 + b1 - (abs(L / m) + abs(base / m) + 2) * m, k2 * a2 + b2 - (abs(L / m) + abs(base / m) + 2) * m);
//     // cout << "base = " << base << endl;
//     // cout << "L = " << L << endl;
//     ll count = ((R - base) / m) - ((L - base) / m)  + (((L - base) % m) == 0 ? 1 : 0);
//     cout << count << endl;
// }
