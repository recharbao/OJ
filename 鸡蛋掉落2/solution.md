动态规划思路:dp[k,n] = 1 + min(max(dp[k-1][x-1],dp[k,n-x])),并用二分查找寻x。
