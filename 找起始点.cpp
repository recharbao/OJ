#include<iostream>
#include<vector>
using namespace std;

 vector<int> searchRange(vector<int>& nums, int target);

int main()
{
    int S[] = {1}, target = 1;
    vector<int> nums(S,S+1);
    vector<int> result;
    result=searchRange(nums,target);
    cout<<result[0]<<","<<result[1]<<endl;
    return 0;
}



 vector<int> searchRange(vector<int>& nums, int target)
 {

     vector<int> result;
     int l=0,r=nums.size()-1;
        while (l<=r)
        {
            int mid=l+(r-l>>2);
            //如果找到
            if(nums[mid]==target)
            {
                int x=mid;
                int y=mid;
                while (x>=0&&nums[x]==target) x--;
                x++;
                while (y<=nums.size()-1&&nums[y]==target) y++;
                y--;
            result.push_back(x);
            result.push_back(y);
            return result;    
            }
            //否则进行二分
            if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
 }

/* 
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=-1,b=-1,i=0,j=nums.size()-1,mid,flag=0;
        while(i<=j){                //i,j控制
            mid=(i+j)/2;
            if(nums[mid]==target){
                flag=1;
                break;
            }
            else
                if(nums[mid]<target)
                    i=mid+1;
                else
                    j=mid-1;
        }
        if(flag){
            a=mid;
            b=mid;
            while(a>=1)
                if(nums[a-1]==target)
                    a--;
                else
                    break;
            int t=nums.size()-2;
            while(b<=t)
                if(nums[b+1]==target)
                    b++;
                else
                    break;
        }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }

*/





