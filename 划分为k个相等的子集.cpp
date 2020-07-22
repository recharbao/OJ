#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool dfs(int cur,vector<int>& nums,int k,vector<int> counter);
bool canPartitionKSubsets(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {1,1,2,4};
    int k = 4;
    bool result;
    result=canPartitionKSubsets(nums,k);
    cout<<result;
    return 0;
}



int sum=0;
bool canPartitionKSubsets(vector<int>& nums, int k) 
{
    sum=accumulate(nums.begin(),nums.end(),0);
    if(sum%k!=0) return false;
    vector<int> counter;
    sort(nums.begin(),nums.end(),greater<int>());
    if((sum/k)>=nums[0])
        counter.push_back(nums[0]);
    else
        return false;
    return dfs(1,nums,k,counter);
}

bool dfs(int cur,vector<int>& nums,int k,vector<int> counter)
{
    if(cur==nums.size()&&counter.size()==k)
       return true;

    else if(cur<nums.size())
    {
        for(int i=0;i<counter.size();i++)
        {
            if((sum/k)-counter[i]>=nums[cur])
            {
                counter[i]+=nums[cur];
                if(dfs(cur+1,nums,k,counter))
                    return true;
                counter[i]-=nums[cur];
            }
        }
  
        if(counter.size()<k&&(sum/k)>=nums[cur])
        {
            counter.push_back(nums[cur]);
            if(dfs(cur+1,nums,k,counter))
                return true;
            counter.pop_back();
        }
    }

    return false;
}
