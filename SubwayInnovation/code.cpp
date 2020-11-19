#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct nums
{
    ll cor;
    ll number;
};

static bool cmp(nums a, nums b)
{
    return a.cor < b.cor;
}

int main()
{
    ll n;
    cin >> n;
    nums s[n];
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        s[i].cor = x;
        s[i].number = i + 1;
    }
    ll k;
    cin >> k;

    sort(s, s + n, cmp);
    vector<ll> preSum(n + 1, 0);
    for(int i = 1; i <= n; i++)
        preSum[i] = preSum[i - 1] + s[i - 1].cor;

    ll pre = 0;
    for(int i = 1; i <= k; i++)
        pre -= (k + 1 - 2 * i) * s[i - 1].cor;

    ll MIN = pre, MINIdex = 0;
    for(int i = k; i < n; i++)
    {
        pre = pre - 2 * (preSum[i] - preSum[i - k + 1]) + (k - 1) * (s[i].cor + s[i - k].cor);
        if(MIN > pre)
        {
            MIN = pre;
            MINIdex = i - k + 1;
        }
        
    }

    for(int i = 0; i < k - 1; i++)
    {
        cout << s[MINIdex + i].number << " ";
    }
    cout << s[MINIdex + k - 1].number << endl;

    return 0;
}
