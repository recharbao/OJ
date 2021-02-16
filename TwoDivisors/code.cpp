#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    vector<int> p(1e7 + 1, 0);
    vector<pair<int, int> > ans;

    for(int i = 2; i <= 1e7; i++)
        if(!p[i]) for(int j = 2 * i; j <= 1e7; j += i) p[j] = i;

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(!p[x]) ans.push_back({-1, -1});
        else
        {
            int a = p[x];
            while (x % (a * p[x]) == 0) a *= p[x];
            if(a == x) ans.push_back({-1, -1});
            else ans.push_back({a, x / a});
        }
    }

    for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i].first);
    printf("\n");
    
    for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i].second);
    printf("\n");

    return 0;
}





















// 超时的解法
/*
#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;

void getPrime(ll n, vector<ll>& res)
{
	int i;
    set<ll> s;
	for (i = 2; i <= sqrt(n); i++)
	{
        bool flag = false;
		while (n != i)
			if (n % i == 0)
			{
                if(!flag && s.count(i) == 0)
                {
                    s.insert(i);
                    flag = true;
                }
				n = n / i;
			}
			else break;
	}

	if(s.count(n) == 0) s.insert(n);

    for(auto it = s.begin(); it != s.end(); it++) res.push_back(*it);

	return;
}


int main()
{
    std::ios::sync_with_stdio(false);    
    std::cin.tie(0);  
    int n;
    cin >> n;
    vector<vector<ll> > ans;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vector<ll> res;
        getPrime(x, res);
        vector<ll> tmp;
        if(res.size() >= 2)
        {
            ll left = res[0], right = 1;
            for(int l = 1; l < res.size(); l++)
            {
               right *= res[l];
            }
            tmp.push_back(left);
            tmp.push_back(right);
            ans.push_back(tmp);
        }
        else
        {
            tmp.push_back(-1);
            tmp.push_back(-1);
            ans.push_back(tmp);
        }
        
    }

    for(int j = 0; j < 2; j++)
    {
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

*/
