#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    vector<int> dp(n + 1, 0);
    vector<int> height(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    for(int i = 1; i <= n; i++)
        dp[i] = dp[i - 1] + nums[i - 1];

    for(int i = n, h = n; i >= 0; i--)
    {
        if (dp[i] > dp[height[h]])  h = i;
        height[i] = h;
    }


    int MINIndex = 0;
    for (int i = 0, MAX = INT32_MIN; i < n; i++)
    {
        if (dp[height[i]] - dp[i] > MAX)
        {
            MINIndex = i;
            MAX = dp[height[i]] - dp[i];
        }
        
    }

    cout << -(accumulate(nums.begin(), nums.begin() + MINIndex, 0) + accumulate(nums.begin() + height[MINIndex], nums.end(), 0)) + accumulate(nums.begin() + MINIndex, nums.begin() + height[MINIndex], 0) << endl;
    return 0;
}






/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    vector<int> preSum(n + 1, 0);
    vector<int> suffSum(n + 1, 0);

    int preIndex = -1, suffIndex = n;

    for (int i = 0; i < n; i++)
    {
        preSum[i + 1] = preSum[i] - nums[i];
        suffSum[i + 1] = suffSum[i] - nums[n - 1 - i];

        if (preSum[preIndex + 1] <= preSum[i + 1])  preIndex = i;
        if (suffSum[n - suffIndex] <= suffSum[i + 1])   suffIndex = n - 1 - i;
    }



    

    if (preIndex >= suffIndex)
    {
        
        if (preSum[preIndex + 1] < suffSum[n - suffIndex])
        {
           reverse(nums.begin(),nums.end());
           vector<int> tmp = preSum;
           preSum = suffSum;
           suffSum = tmp;

           int ex = suffIndex;
           suffIndex = n - 1 - preIndex;
           preIndex = n - 1 - ex;
        }
       
        int maxIndex = n;
        for (int i = preIndex + 1; i < n; i++)
        {
            if (suffSum[n - i] > 0 && (maxIndex == n || suffSum[n - i] > suffSum[n - maxIndex]))
            {
                maxIndex = i;
                
            }
        }
        //cout << "max = " << maxIndex << endl;
        cout << -(accumulate(nums.begin(), nums.begin() + preIndex + 1, 0) + accumulate(nums.begin() + maxIndex, nums.end(), 0)) + accumulate(nums.begin() + preIndex + 1, nums.begin() + maxIndex, 0) << endl;
    }
    else
        cout << -(accumulate(nums.begin(), nums.begin() + preIndex + 1, 0) + accumulate(nums.begin() + suffIndex, nums.end(), 0)) + accumulate(nums.begin() + preIndex + 1, nums.begin() + suffIndex, 0) << endl;

    return 0;
}

*/










/*

8
0 0 0 1 -1 -1 -2 3

8
1 -30 2 2 0 -39 23 6


8
6 23 -39 0 2 2 -30 1


7
-17 6 5 0 1 4 -1


7
-1 4 1 0 5 6 -17


30
8 -1 3 -7 0 -1 9 3 0 0 3 -8 8 -8 9 -3 5 -9 -8 -10 4 -9 8 6 0 9 -6 1 5 -6



*/

