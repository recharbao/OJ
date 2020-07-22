#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> flag(vector<int> nums,int point);

int main()
{
    vector<int>nums{2,3,1,9,7,6,1,4,5,645,4,7,32,5,2,56,7,8,3,6,54,23,435,54,5,87,8,4,3,2,1,5,6,7,658,9,6,4,2,1,6,7,4,4,4,4,4,4,4,4};
    int point=4;
    vector<int>result=flag(nums,point);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
}


vector<int> flag(vector<int> nums,int point)
{
    int less=-1;
    int more=nums.size();
    int L=0;
    while (L<more)
        if(nums[L]>point) swap(nums[L],nums[--more]);
        else if(nums[L]<point) swap(nums[L++],nums[++less]);
        else L++;
    return nums;
}