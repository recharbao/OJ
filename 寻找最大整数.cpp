#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string largestNumber(vector<int>& nums);

int main()
{
    int a[]={3,4421,43,5,67,89,123,315,3,2,8};
    vector<int> nums(a,a+11);
    string H;
    H=largestNumber(nums);
    cout<<H;
    return 0;
}


/* 
class Solution {
public:
    static bool cmp(int a,int b)
    {
        string s = to_string(a);
        string t = to_string(b);
        return s+t > t+s;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string t;
        for(int i = 0; i < nums.size();++i)
            t+=to_string(nums[i]);
        return t[0] == '0' ? "0" : t;
    }
};

*/







static bool cmp(int a,int b)
{
    string s=to_string(a);
    string t=to_string(b);
    return s+t>t+s;
}





string largestNumber(vector<int> &nums)
{
    sort(nums.begin(),nums.end(),cmp);
    string t;
    for(int i=0;i<nums.size();i++)
    {
        t+=to_string(nums[i]);
    }
    return t[0]=='0'? "0":t;
}




