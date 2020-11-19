#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int q;
    cin >> q;
    vector<vector<int> > nums(q);
    for(int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            nums[i].push_back(x);
        }
    }

	for(int i = 0; i < q; i++)
	{
		int ans = 1;
		int count = 1;
		int result = 1;
		map<int, vector<int> > numsPoint;

		for(int j = 0; j < nums[i].size(); j++)
			numsPoint[nums[i][j]].push_back(j);

		for(auto it = numsPoint.begin(); it != std::prev(numsPoint.end(), 1);)
		{
			count++;
			vector<int> tmpPre = it -> second;
			vector<int> tmpSuff = (++it) -> second;
			int m = tmpPre.size() - 1;

			if(tmpPre[m] < tmpSuff[0]) ans++;
			else
				ans = 1;

			result = max(result, ans);
		}

		cout << count - result << endl;
	}

    return 0;
}















/*

1
4
1 3 2 4

*/






/*

#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;
const int INF = int(1e9) + 99;

int t, n;
int a[N];
int l[N], r[N];
int dp[N];

int main() {
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			l[i] = INF;
			r[i] = -INF;
			dp[i] = 0;
		}

		vector <int> v;	
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			--a[i];
			v.push_back(a[i]);
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	
		int res = n;
		for(int i = v.size() - 1; i >= 0; --i){
			if(i + 1 == v.size() || r[v[i]] >= l[v[i + 1]]) dp[i] = 1;
			else dp[i] = 1 + dp[i + 1];
			res = min(res, int(v.size())- dp[i]);
		}

		printf("%d\n", res);
	}	

	return 0;
}                             	
*/
