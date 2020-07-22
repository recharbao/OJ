#include<iostream>
#include<vector>
using namespace std;

int maxSumDivThree(vector<int>& nums);

int main()
{
    vector<int> nums{1};
    int result;
    result=maxSumDivThree(nums);
    cout<<result;
    return 0;
}


int maxSumDivThree(vector<int>& nums)
{
    vector<int> dp(3,0);
    vector<int>dp1(3,0);
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            int rest=(dp[j]+nums[i])%3;
            dp1[rest]=max(dp1[rest],dp[j]+nums[i]);
        }
        for(int j=0;j<3;j++)
            dp[j]=dp1[j];
    }
    return dp[0];
}