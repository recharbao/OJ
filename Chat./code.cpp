/*#include<iostream>
#include<algorithm>
#include<vector>
#define cyc(i,a,b) for(int i = a; i <= int(b); i++)
using namespace std;

typedef long long ll;



//注意引用
void SortSum(vector<ll>& a)
{
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());    
    cyc(i, 1, a.size() - 1) a[i] += a[i - 1];
}


int main()
{
    int n, d, m;
    int k = 0,l = 0;
    cin >> n >> d >> m;
    vector<ll> x, y;
    x.push_back(0);
    y.push_back(0);

    for (int i = 0, num; i < n; i++)
    {
        cin >> num;
        if (num > m){
            x.push_back(num);
        }
        else {
            y.push_back(num);
        }
    }

    k = x.size() - 1;
    l = y.size() - 1;

    if (k == 0)
    {
        ll s = 0;
        cyc(i,1,n) s += y[i];
        cout << s << endl;
        return 0;
    }

    SortSum(x);
    SortSum(y);

    fill(y.begin()+l+1, y.begin()+n+1, y[l]);
    ll ans = 0;

    cyc(i, (k + d)/(d + 1), k) if(1ll * (i - 1) * (d + 1) + 1 <= n){
        ans = max(ans, x[i] + y[n - 1ll * (i -1) * (d + 1) - 1]);
    }

    cout << ans <<endl;

    return 0;
}

*/

#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
using namespace std;

typedef long long ll;
const int maxn = 1e5;
int n, d, m, k, l;
ll a[maxn + 5], b[maxn + 5];

void solve(ll a[], int n) {
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	rep(i, 1, n) a[i] += a[i - 1];
}

int main() {
	scanf("%d %d %d", &n, &d, &m);
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		if (x > m) a[++k] = x;
		else b[++l] = x;
	}
	if (k == 0) {
		ll s = 0;
		rep(i, 1, n) s += b[i];
		printf("%lld\n", s);
		exit(0);
	}
	solve(a, k);
	solve(b, l);
	fill(b + l + 1, b + n + 1, b[l]);
	ll res = 0;
	rep(i, (k + d) / (1 + d), k) if (1ll * (i - 1) * (d + 1) + 1 <= n) {
		res = max(res, a[i] + b[n - 1ll * (i - 1) * (d + 1) - 1]);
	}
	printf("%lld\n", res);
	return 0;
}



