#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll dx(ll x);

int main()
{
    ll N;
    cin >> N;
    vector<ll> count(10, 0);
    for(int i = 1; i <= N; i++)
    {
        count[dx(i)]++;
    }

    ll res = 0;
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            for(int k = 1; k <= 9; k++)
            {
                if(i * j % 9 == k % 9)
                {
                    res += count[i] * count[j] * count[k];
                }
            }
        }
    }

    for(int i = 1; i <=N; i++)
    {
        res -= N / i;
    }

    cout << res << endl;

    return 0;
}

ll dx(ll x)
{
    if(x % 9)
    {
        return x % 9;
    }
    return 9;
}

