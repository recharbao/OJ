#include<iostream>
#include<vector>
using namespace std;

int minPatches(vector<int>& nums, int n);

int main()
{
    vector<int> nums{1,5,10};
    int result = 0;
    result = minPatches(nums,20);
    cout << result << endl;
    return 0;
}

int minPatches(vector<int>& nums, int n) {
     long extendNums = 0;
    int addNum = 0;
    int index = 0;

    for (long i = 1; i <= n; i = extendNums + 1)
    {
        if(extendNums < i && index < nums.size() && nums[index] <= i)
        {
            extendNums += nums[index];
            index++;
        }
        else if(extendNums < i)
        {       
           addNum++;
           extendNums += i;             
        }
    }
    return addNum;
}
