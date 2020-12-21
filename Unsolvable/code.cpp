#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int MSprime[45] = {2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,
                2203,2281,3217,4253,4423,9689,9941,11213,
                19937,21701,23209,44497,86243,110503,132049,216091,
                756839,859433,1257787,1398269,
                2976221,3021377,6972593,13466917,20996011};


ll ppow (ll num , ll x)
{
    ll ret = 1;
    while ( x )
    {
        if ( x&1 ) 
        {
            ret *= num;
            ret %= mod;
        }
        num *= num;
        num %= mod;
        x >>= 1;
    }
    return ret;
}


int main()
{

    int n;
    cin >> n;

    cout << ppow(2, MSprime[n - 1] - 1) - 1 << endl;
    
    return 0;
}

