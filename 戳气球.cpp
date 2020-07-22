#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxCoins(vector<int>& nums);
int dfs(int left,int right,vector<int>& num,vector<vector<int> >& dp);

int main()
{
    int a[4] = {1,1,1,1};
    vector<int> nums(a,a+4);
    int result = maxCoins(nums);
    cout<<result<<endl;
    return 0;
}

int maxCoins(vector<int>& nums)
{
    if(nums.size() == 0)
        return 0;
    int n = nums.size();
    vector<int>num(n+2,1);
    vector<vector<int> >dp(n+2,vector<int>(n+2,-1));

    for(int i = 0; i < n; i++)
        num[i + 1] = nums[i];

    return dfs(0,n+1,num,dp);
}


int dfs(int left,int right,vector<int>& num,vector<vector<int> >& dp)
{
    if(left == right - 1)   return 0;

    if(dp[left][right] != -1)   return dp[left][right];

    for(int i = left + 1; i < right; i++)
        dp[left][right] = max(dfs(left,i,num,dp) + dfs(i,right,num,dp) + num[left] * num[right] * num[i],dp[left][right]);

    return dp[left][right];
}