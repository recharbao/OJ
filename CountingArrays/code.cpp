#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
//组合常用模板
const int N = 2000000 + 5;
const int MOD = (int)1e9 + 7;
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


 
ll fast_mod(ll a, ll n, ll Mod)
{
    ll ans=1;
    a%=Mod;
    while(n)
    {
        if(n&1) ans=(ans*a)%Mod;
        a=(a*a)%Mod;
        n>>=1;
    }
    return ans;
}


//质数分解模板
void getPrime(vector<int> &prime, int n)
{
  for(int i = 2;i * i <= n;i++)
    while(n != i)
    {
      if(n % i == 0)
      {
        prime.push_back(i);
        n=n / i;
      }
      else
        break;
    }
    if(n > 1)
        prime.push_back(n);
}



int main()
{
    init();
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int q;
    cin >> q;
    for(int t = 0; t < q; t++)
    {
        int x, y;
        cin >> x >> y;

        
        vector<int> prime;
        getPrime(prime, x);
        map<int, int> cnt;
        for(int i = 0; i < prime.size(); i++) cnt[prime[i]]++;

        vector<int> nums;
        int c = 0;
        for(auto it = cnt.begin(); it != cnt.end(); it++) nums.push_back(it -> second);

        ll res = 1;
        y--;
        for(int i = 0; i < nums.size(); i++)
        {
            res *= comb(nums[i] + y, y);
            res %= MOD;
        }
        

        res = (res *fast_mod(2, y, MOD)) % MOD;
        
        cout << res << endl;
    }
    return 0;
}




