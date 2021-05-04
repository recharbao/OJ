#include<bits/stdc++.h>
#include<numeric>
using namespace std;

typedef long long ll;

ll a[1000000], b[1000000], suff[1000000], m[1000000];   // 在函数里面写会是随机数， 出错好几遍了， 注意一下


int main()
{
    int n, k;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    for(int i = n; i > 0; i--) suff[i] = suff[i + 1] + a[i];
    m[0] = INT64_MAX;
    for(int i = 1; i <= n; i++) m[i] = min(m[i - 1], b[i]);

    ll ans = 0;
    if (k == 0)
        for(int i = 1; i <= n; i++) ans = max(ans, suff[i] - b[i]);
    else if (k >= 2)
        ans = max(ans, max(suff[1] - m[n - 1], a[n] - b[n]));
    else
    {
        for(int i = 2; i <= n; i++) ans = max(ans, max(0ll, suff[1] - suff[i] - m[i - 1]) + max(0ll, suff[i] - b[i]));
        for(int i = 1; i < n - 1; i++) ans = max(ans, suff[1] - a[i + 1] - b[1] + max(0ll, a[i + 1] - b[i + 1]));
    }
    
    cout << ans << endl;
    
    return 0;
}
