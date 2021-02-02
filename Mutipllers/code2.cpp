
//下面的简化时间复杂度的写法，思路有了，但是实在过不了，无奈。

#include<bits/stdc++.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

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

int main()
{
    std::ios::sync_with_stdio(false);    
    std::cin.tie(0);     // IO

    ll m;
    cin >> m;
    ll num = 1ll;
    map<ll, ll> count;
    for(int i = 0; i < m; i++)
    {
        ll p;
        cin >> p;
        count[p]++;
    }



    //for(auto it = count.begin(); it != count.end(); it++) num *= (it -> second + 1);

    /*
    ll res = 1ll;
    for(auto it = count.begin(); it != count.end(); it++)
    {
        ll a = it -> first;
        ll b = it -> second;
        ll tmp = fast_mod(a, b * (b + 1) / 2, mod);

        for(auto it2 = count.begin(); it2 != count.end(); it2++)
        {
            tmp = fast_mod(tmp, it != it2 ? (it2 -> second + 1) : 1, mod) % mod;
        }

        res = (res * tmp % mod);

        //res = (res * fast_mod(tmp, num / (b + 1), mod) % mod);
    }
    */
   /*
   ll res = 1ll;
   vector<ll> a;
   vector<ll> b;
   for(auto it = count.begin(); it != count.end(); it++)
   {
       a.push_back(it -> first);
       b.push_back(it -> second);
   }
   for(int i = 0; i < a.size(); i++)
   {
       ll x = a[i];
       ll y = b[i];
       ll tmp = fast_mod(x, y * (y + 1) / 2, mod);
       for(int j = 0; j < b.size(); j++)
       {
           tmp = fast_mod(tmp, i != j ? (b[j] + 1) : 1, mod) % mod;
       }
       res = (res * tmp % mod);
   }

    cout << res << endl;
    */
    
    vector<ll> a;
    vector<ll> b;
    for(auto it = count.begin(); it != count.end(); it++)
    {
        a.push_back(it -> first);
        b.push_back(it -> second + 1);
    }

    ll pre = 1ll;
    for(int i = 0; i < a.size(); i++)
    {
        ll x = a[i];
        ll y = b[i];
        cout << "x = " << x <<"   ";
        cout << "y = " << y << endl;
        pre = (fast_mod(pre, y, mod) * ((i == (a.size() - 1) && a.size() != 1) ? 1ll : fast_mod(x, y * (y - 1) / 2, mod))) % mod;
        cout << "pre =  " << pre << endl;
    }

    ll suff = 1ll;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        ll x = a[i];
        ll y = b[i];
        suff = (fast_mod(suff, y, mod) * ((i == 0 && a.size() != 1) ? 1ll : fast_mod(x, y * (y - 1) / 2, mod))) % mod;
    }

    ll res = (a.size() == 1 ? pre : (pre * suff)) % mod;

    
    //cout << "pre = " << pre << endl;
    //cout << "suff = " << suff << endl;


    cout << res << endl;


    /*
    ll tmp = 1ll;
    for(int i = 0; i < a.size(); i++)
    {
        ll x = a[i];
        ll y = b[i];
        tmp = (tmp * fast_mod(x, y * (y - 1) / 2, mod) % mod);
    }
    */

    return 0;
}








/*
#include<bits/stdc++.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

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

int main()
{
    ll m;
    cin >> m;
    map<ll, ll> count;
    for(int i = 0; i < m; i++)
    {
        ll p;
        cin >> p;
        count[p]++;
    }

    vector<int> prod;
    ll num = 1ll;
    for(auto it = count.begin(); it != count.end(); it++)
    {
        num *= (it -> second + 1);

    }

    ll res = 1ll;
    for(auto it = count.begin(); it != count.end(); it++)
    {
        ll a = it -> first;
        ll b = it -> second;
        ll tmp = fast_mod(a, b * (b + 1) / 2, mod);
        res = (res * fast_mod(tmp, num / (b + 1), mod) % mod);
    }

    cout << res << endl;

    return 0;
}
*/

