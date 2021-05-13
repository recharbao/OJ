#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
//组合常用模板
const ll N = 2000000 + 5;
const ll MOD = (int)1000000007;
ll F[N], Finv[N], inv[N];//F是阶乘，Finv是逆元的阶乘
void init(){
    inv[1] = 1;
    for(int i = 2; i < N; i ++){
        inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
    }
    F[0] = Finv[0] = 1;
    for(int i = 1; i < N; i ++){
        F[i] = F[i-1] * 1ll * i % MOD;
        Finv[i] = Finv[i-1] * 1ll * inv[i] % MOD;
    }
}
ll comb(ll n, ll m){//comb(n, m)就是C(n, m)
    if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}


int main()
{
    init();
    ll n, m, k;
    cin >> n >> m >> k;

    cout << (comb(n - 1, 2 * k) * comb(m - 1, 2 * k)) % MOD << endl;
    
    return 0;
}
