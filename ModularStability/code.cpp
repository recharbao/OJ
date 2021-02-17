#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
//组合常用模板
const int N = 2000000 + 5;
const int MOD = (int)998244353;
int F[N], Finv[N], inv[N];//F是阶乘，Finv是逆元的阶乘
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
int comb(int n, int m){//comb(n, m)就是C(n, m)
    if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}


int main()
{
    init();
    int n, k;
    cin >> n >> k;
    
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        int b = n / i;
        res = (res + comb(b - 1, k - 1)) % MOD ;
    }

    cout << res << endl;
    
    return 0;
}
