#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums);

int main()
{
    vector<int>nums{1,-2,4,2,8,-7,2,-1,9,3,7,7,6,0,-1,6};
    vector<int> next;
    next=nextGreaterElements(nums);
    for(int i=0;i<next.size();i++)
        cout<<next[i]<<endl;
    return 0;
}

vector<int> nextGreaterElements(vector<int>& nums)
{
    int n=nums.size();
    vector<int> next(n,-1);
    stack<int> s;
    for(int i=0;i<2*n;i++)
    {               
        int num=nums[i%n];
        while (!s.empty()&&nums[s.top()]<num)
        {
            next[s.top()]=num;
            s.pop();
        }
        if(i<n)
        {
            s.push(i);
        }
    }
    return next;
}

