#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
int FindMedian(vector<int>& nums1, vector<int>& nums2, int k);



int main()
{
    vector<int> nums1 = {1,2,4,9};
    vector<int> nums2 = {1,2,3,4,5,6};
    double result = findMedianSortedArrays(nums1,nums2);
    cout << result <<endl;
    return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //计算出nums1和nums2的总个数:
    int sum = nums1.size() + nums2.size();
    //奇数
    if (sum % 2 == 1)
    {
        return FindMedian(nums1, nums2, sum / 2 + 1);
    }
    else
    {
        return (FindMedian(nums1, nums2, sum / 2) + FindMedian(nums1, nums2, sum / 2 + 1)) / 2.0;   
    }
}


//寻找第k个数
int FindMedian(vector<int>& nums1, vector<int>& nums2, int k)
{
    int length1 = nums1.size(), length2 = nums2.size();
    int index1 = 0, index2 = 0;
    while (true)
    {
        //处理边界
        if (index1 == length1)
        {
            return nums2[index2 + k - 1];
        }
        if (index2 == length2)
        {
            return nums1[index1 + k - 1];
        }
        if (k == 1)
        {
            return min(nums1[index1], nums2[index2]);
        }

        int half = k / 2;
        int newIndex1 = min(length1, index1 + half) - 1;
        int newIndex2 = min(length2, index2 + half) - 1;
        if (nums1[newIndex1] < nums2[newIndex2])
        {
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }
        else
        {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
    
}

    
