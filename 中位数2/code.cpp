
#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result <<endl;
    return 0;
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   if (nums1.size() > nums2.size())
   {
       return findMedianSortedArrays(nums2,nums1);
   }

   int m = nums1.size();

   int n = nums2.size();

   int left = 0, right = m;

   int median1 = 0, median2 = 0;

   while (left <= right)
   {
       //后面的比前面的多一个
       int i = (left + right) / 2;
       int j = (m + n + 1) / 2 - i;

       int nums1_im1 = (i == 0 ? INT32_MIN : nums1[i - 1]);
       int nums1_i = (i == m ? INT32_MAX : nums1[i]);
       int nums2_jm1 = (j == 0 ? INT32_MIN : nums2[j - 1]);
       int nums2_j = (j == n ? INT32_MAX : nums2[j]);

       if (nums1_im1 <= nums2_j)
       {
           median1 = min(nums1_i, nums2_j);
           median2 = max(nums1_im1, nums2_jm1);
           left = i + 1;
       }
       else
       {
           right = i - 1;   
       }
   }
   
   return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median2;
}
