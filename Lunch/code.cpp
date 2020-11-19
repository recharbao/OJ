/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
 
    int que[n];
 
    for(int i = 0; i < n; i++)
    {
        cin >> que[i];
    }
 
    vector<vector<int> > p(m,vector<int>(2,0));
 
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vector<int> tmp;
        tmp.push_back(u);
        tmp.push_back(v);
        p.push_back(tmp);
    }
    
    bool flag = true;
    int pivot = n - 1;
 
    while (flag)
    {
        flag = false;
        for (int i = pivot; i > 0; i--)
        {
            int u = que[i - 1];
            int v = que[i];
 
            for(int j = 0; j < p.size(); j++)
            {
                if (p[j][0] == u && p[j][1] == v)
                {
                    if (i == pivot)
                    {
                        pivot--;
                        ans++;
                    }
                    
                    p.erase(p.begin() + j);
                    swap(que[i], que[i - 1]);
                    flag = true;
                    break;
                }
            }
        }
        
    }
    
    cout << ans << endl << endl;
    
    return 0;
}
 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
 
 
using namespace std;
 
//0x9e3779b9
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 9999999999999 + (seed<<11) + (seed>>1);
        }
        return seed;
    }
};
 
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
 
    int que[n];
 
    for(int i = 0; i < n; i++)
    {
        cin >> que[i];
    }
 
    unordered_set<vector<int>, VectorHash> p;
 
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vector<int> tmp;
        tmp.push_back(u);
        tmp.push_back(v);
        p.insert(tmp);
    }
    
    bool flag = true;
    int pivot = n - 1;
    int i = n - 2;
 
    while (flag)
    {
        flag = false;
        for (i < pivot ? ++i : i = pivot; i > 0; --i)
        {
            vector<int> tmp;
            tmp.push_back(que[i - 1]);
            tmp.push_back(que[i]);
            if (p.erase(tmp))
            {
                if (i == pivot)
                {
                    pivot--;
                    ans++;
                }
                swap(que[i], que[i - 1]);
                flag = true;
                break;
            }
            if (p.empty())
            {
                break;
            }
            
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
}
 
 
/*
 
#include <bits/stdc++.h>
//#pragma comment(linker, ”/STACK:36777216“)
 
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
 
int n, m;
vector<int> a, was;
vector<vector<int> > g;
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    g.resize(n);
    was.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < m; i++){
    	int w1, w2;
    	cin >> w1 >> w2;
    	w1--; w2--;
    	g[w1].pb(w2);
    }
 
    reverse(all(a));
    int ans = 0;
 
    for (int i = 0; i < n; i++) was[i] = 0;
    was[a[0]] = 1;
	int cnt = 1;
	for (int i = 1; i < n; i++){
		int cnt2 = 0;
		for (int to : g[a[i]]){
			if (was[to]) cnt2++;
		}
		if (cnt == cnt2){
			ans++;
		} else {
			was[a[i]] = 1;
			cnt++;
		}
	}
 
    cout << ans;
}
 
*/
 
