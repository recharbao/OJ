#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, ans = -1;
    cin >> n;
    vector<int> nums;  //注意从小到大已经排列
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    for(int i = 0; i < n; i++)
    {
        //val_i > val_j
        for(int j = i + 1; j < n; j++)
        {
            int re = nums[i] - 1;  //这个-1很有讲究，想:如果不-1，那么可能不是最小;如果-2或者更多，可能同样的效果，但是如果-1符合时，那么就漏掉了。
            int count1 = 1;
            int count2 = 0;
            for(int k = i + 1; k <= j; k++)
            {
                count1 += re / nums[k];
                re %= nums[k];
            }

            int aimTol = nums[i] - 1 - re + nums[j];

            for(int k = 0; k < n; k++)
            {
                count2 += aimTol / nums[k];
                aimTol %= nums[k];
            }
            if(count1 < count2 && (ans == -1 || ans > aimTol)) ans = nums[i] - 1 - re + nums[j];
        }
    }

    cout << ans << endl;

    return 0;
}
