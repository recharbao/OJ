#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums);

int main()
{
    vector<int>nums{2,0,2,1,1,0};
    sortColors(nums);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i];
    return 0;
}



void sortColors(vector<int>& nums)
{
    int less=-1;
    int more=nums.size();
    int L=0;
    while (L<more)
    {
        if(nums[L]>1)
        {
            swap(nums[L],nums[--more]);
        }
        else if(nums[L]<1)
        {
            swap(nums[L++],nums[++less]);
        }
        else
        {
            L++;
        }
    }
}


{a1,a2,a3,a4,a5,a6};

class Solution {
public:
    void sortColors(vector<int> &nums) {
        if (nums.empty()) return;
        int start = 0, end = nums.size() - 1;
        for (int i = 0; i <= end; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[start++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[end--]);
            }
        }
    }
};



