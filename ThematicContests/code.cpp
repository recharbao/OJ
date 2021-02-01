
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> nums;
    for(auto it = cnt.begin(); it != cnt.end(); it++) nums.push_back(it -> second);

    sort(nums.begin(), nums.end());

    int ans = 0;
    for(int i = 1; i <= nums.back(); i++)
    {
        int index = nums.size() - 1;
        int val = i;
        int res = i;
        while (val % 2 == 0 && index > 0)
        {
            val /= 2;
            index--;
            if(nums[index] < val) break;
            res += val;
        }
        ans = max(ans, res);
    }

    cout << ans << endl;

    return 0;
}


