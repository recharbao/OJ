#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int find(int v);
ll get(int cnt);
void merge(int u, int v);

vector<int> p, rk;
ll res;

int main()
{
    int n, m;
    cin >> n >> m;

    res = 0;
    p = rk = vector<int>(n, 1);
    iota(p.begin(), p.end(), 0);

    vector<pair<int, pair<int, int> > > edge(n - 1);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
        edge[i].second.first--;
        edge[i].second.second--;
    }

    vector<pair<int, int> > q(m);
    vector<ll> ans(m);

    for(int i = 0; i < m; i++)
    {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(edge.begin(), edge.end());
    sort(q.begin(), q.end());


    int pos = 0;
    for(int i = 0; i < m; i++)
    {
        while (pos < n - 1 && edge[pos].first <= q[i].first)
        {
            int u = edge[pos].second.first;
            int v = edge[pos].second.second;
            merge(u, v);
            pos++;
        }
        ans[q[i].second] = res;
    }

    for(int i = 0; i < m; i++)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}

int find(int v)
{
    if(v == p[v]) return v;
    return p[v] = find(p[v]);
}

ll get(int cnt) 
{
	return cnt * 1ll * (cnt - 1) / 2;
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);

    if(rk[u] < rk[v]) swap(u, v);

    res -= get(rk[u]);
    res -= get(rk[v]);

    rk[u] += rk[v];

    res += get(rk[u]);

    p[v] = u;
}

