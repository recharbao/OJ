#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

typedef long long ll;

ll n, a, b;

static bool cmp(vector<int> s, vector<int> t)
{
    return (s[0] - s[1]) > (t[0] - t[1]);
}


int main()
{
    std::ios::sync_with_stdio(false);    
    std::cin.tie(0);     
    cin >> n >> a >> b;

    if(b > n) b = n;

    vector<vector<int> > nums;
    for(int i = 0; i < n; i++)
    {
        int hp, dmg;
        cin >> hp >> dmg;
        vector<int> tmp;
        tmp.push_back(hp);
        tmp.push_back(dmg);
        nums.push_back(tmp);
    }

    ll pa = pow(2, a);
    sort(nums.begin(), nums.end(), cmp);

    ll sum = 0;
    for(int i = 0; i < b; i++)
        sum += max(nums[i][0], nums[i][1]);

    for(int i = b; i < n; i++)
        sum += nums[i][1];

    ll res = sum;
    for(int i = 0; i < n; i++)
    {
        if (i < b){ if(res < (sum + pa * nums[i][0] - max(nums[i][0], nums[i][1]))) res = sum + (pa * nums[i][0] - max(nums[i][0], nums[i][1])); }
        else if(b > 0 && res < (sum + nums[b - 1][1] - (max(nums[b - 1][0],  nums[b - 1][1])) + (pa * nums[i][0] - nums[i][1]))) res = (sum + nums[b - 1][1] - (max(nums[b - 1][0],  nums[b - 1][1])) + (pa * nums[i][0] - nums[i][1]));
    }

    cout << res << endl;

    return 0;
}



/*

3 1 2
7 10
4 3
2 1

3 1 2
9 12
4 3
2 1


3 1 2
12 18
4 3
2 1


3 1 2
3 1
5 6
1 0

*/





