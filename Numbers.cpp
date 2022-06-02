#include<bits/stdc++.h>
#include<map>
#include<set>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll solve(ll n, ll p);

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll res = solve(b, k) - solve(a - 1, k);
    cout << res << endl;
    return 0;
}


bool NotPrime(ll n)
{
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}

ll solve(ll n, ll p)
{
    if(p > n || NotPrime(p)) return 0;
    if (p * p > n) return 1;

    ll res = n / p;
    for (int i = 2; i < p; i++) {
        res -= solve(n / p, i);
    }
    return res;
}

