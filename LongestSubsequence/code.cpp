#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);    
    std::cin.tie(0);     // IO  
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    vector<int> count(1e6 + 6, 0);
    vector<int> lcm(1e6 + 6, 0);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x <= m)
        {
            count[x]++;
        }
        nums.push_back(x);
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j * i <= m; j++)
        {
            lcm[i * j] += count[i];
        }
    }

    int l, k = INT32_MIN;
    for(int i = 1; i <= m; i++)
    {
        if(k < lcm[i])
        {
            l = i;
            k = lcm[i];
        }
    }

    cout << l << " " << k << endl;
    for(int i = 0; i < n; i++)
    {
        if(l % nums[i] == 0)
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}

//注意 1e6 * 1e6 时间在 857ms
