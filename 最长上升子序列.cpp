#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums);

int main()
{
    return 0;
}


int lengthOfLIS(vector<int>& nums) 
{
    int n=nums.size();
    if(n==0)return 0;
    if(n==1)return 1;
    vector<int> dp(n,1);
    int MAX = INT_MIN;
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(nums[i]>nums[j])
            {
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        MAX =max(MAX,dp[i]);
    }
    return MAX;        
}