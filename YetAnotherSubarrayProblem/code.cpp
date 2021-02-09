#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> b;
    for(int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        b.push_back(m * a - k);
    }

    vector<ll> preSum(n + 1, 0);
    for(int i = 1; i <= n; i++)
        preSum[i] = preSum[i - 1] + b[i - 1];

    vector<ll> maxI(n + 1, 0);
    for(int i = m; i <= n; i++)
        maxI[i] = max(0ll, maxI[i - m] + preSum[i] - preSum[i - m]);

    ll res = 0;
    for(int t = 1; t <= m; t++)
        for(int i = t; i <= n; i++)
            res = max(res, preSum[i] - preSum[i - t] + maxI[i - t] + k * t);

    cout << max(0ll, res / m - k) << endl;

    return 0;
}




/*
// 这是一上来想到的方法， 时间复杂度超标

#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;

ll b[300000 + 5];
ll preSum[300000 + 10];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        preSum[i + 1] = preSum[i] + (m * a - k);
    }

    ll res = 0;
    for(int l = 0; l < n; l++)
    {
        for(int r = l + 1; r <= n; r++)
        {
            ll e = (m - (r - l) % m) == m ? 0 : (m - (r - l) % m);
            res = max(res, preSum[r] - preSum[l] - k * e);
        }
    }

    cout << res / m << endl;

    return 0;
}
*/

