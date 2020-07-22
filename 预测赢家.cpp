#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//要回看


bool PredictTheWinner(vector<int>& nums);

int winner(vector<int> &nums, int s, int e, int turn);

int main()
{
    vector<int> nums{1,5,2};
    bool result;
    result=PredictTheWinner(nums);
    cout<<result;
    return 0;
}
/*
bool PredictTheWinner(vector<int>& nums)
{
    vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
    //vector<vector<int>> dp;/这样做不可以因为没有给数组初始大小无法使用数组下标进行访问；
     //dp[i][j]是指剩余[i.....j]时  ，当前操作选手与另一位选手的最大分数之差。
     //dp[i][j]=max(dp[i+1][j],dp[i][j-1]),假设dp[i][j]时玩家一出手，玩家一比玩家二多的分数（玩家一-玩家二），
     //dp[i+1][j],或者dp[i][j-1],时玩家二出手，玩家二比玩家一多的分数（玩家二-玩家一）
     //dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);

    for(int i = 0;i < nums.size();i++)
    {
        dp[i][i] = nums[i];
    }

    for(int length = 1;length < nums.size();length++)//这种查找的形式
    {
        for(int i = 0,j = length;j < nums.size();i++,j++)
        {
            dp[i][j] = max(nums[i] - dp[i + 1][j],nums[j] - dp[i][j - 1]);
            cout<<dp[i][j]<<endl;
        }
    }
    return dp[0][nums.size()-1]>=0;
}
*/
/*
    bool PredictTheWinner(vector<int>& nums) {
       int len=nums.size();
       vector<int>ans(len);
       for(int i=0;i<len;i++)ans[i]=nums[i];
       for(int i=len-1;i>=0;i--){
           for(int j=i+1;j<len;j++){
           ans[j]=max(nums[i]-ans[j],nums[j]-ans[j-1]);
           }
       }
       return ans[len-1]>=0;
    }



 class Solution {
    public: bool PredictTheWinner(vector<int> &nums) {
        return winner(nums, 0, nums.size() - 1, 1) >= 0;
    }
    public: int winner(vector<int> &nums, int s, int e, int turn) {
        if (s == e)
            return turn * nums[s];
        int a = turn * nums[s] + winner(nums, s + 1, e, -turn);
        int b = turn * nums[e] + winner(nums, s, e - 1, -turn);
        return turn * max(turn * a, turn * b);
    }
};
*/

//递归使用

bool PredictTheWinner(vector<int> &nums) 
{
    return winner(nums,0,nums.size()-1,1)>=0;
}

int winner(vector<int> &nums, int s, int e, int turn)
{
    if(s==e)
        return turn*nums[s];
    int a=turn*nums[s]+winner(nums,s+1,e,-turn);
    int b=turn*nums[e]+winner(nums,s,e-1,-turn);
    return turn * max(turn * a, turn * b);//关键的值的调整；
}



