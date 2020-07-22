#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums,int target);


int main()
{
    int a[] = {4,5,6,7,0,1,2};
    vector<int> nums(a,a+7);
    int target=0;
    int result=search(nums,target);
    cout<<result;
    
    return 0;

}


  

int search(vector<int> &nums,int target)
{
    int l=0,r=nums.size()-1;
    while (l<=r)
    {
        int mid=l+(r-l>>1);
        if (nums[mid] == target) return mid;
        //??????
        if(nums[mid]<nums[r])
        {
            if(nums[mid]<target&&nums[r]>=target) l=mid+1;
            else r=mid-1;
        }
        //??????
        if(nums[mid]>=nums[l])
        {
            if(nums[mid]>target&&nums[l]<=target) r=mid-1;
            else l=mid+1;
        }
    }
    return -1;
}























