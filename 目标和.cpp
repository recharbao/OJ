#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int solve(int target,vector<int>&nums);
int findTargetSumWays(vector<int>& nums, int S);

int main()
{
    vector<int> nums{14,45,15,50,1,23,37,12,30,26,42,21,15,12,8,28,16,4,16,47};
    int S=6;    
    int result;
    result=findTargetSumWays(nums,S);
    cout<<result;
    return 0;
}

int findTargetSumWays(vector<int>& nums, int S)
{
    int sum=accumulate(nums.begin(),nums.end(),0);
    if((sum-S)<0||(sum-S)%2!=0) return 0;
    int target=(sum-S)/2;
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<nums.size();i++)
        for(int j=target;j>=nums[i];j--)
                dp[j]+=dp[j-nums[i]];
    return dp[target];
}





