#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
 
static bool cmp(int a, int b)
{
    return a > b;
}
 
int main()
{
    int n;
    cin >> n;
    vector<int> nums1;
    set<int> nums2;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums1.push_back(x);
        nums2.insert(-x);
    }
 
    for(int i = 0; i < n; i++)
    {
        int val = nums1[i];
        if(nums2.upper_bound(-val) != nums2.end())
        {
            auto res = nums2.upper_bound(-val);
            cout << -*res << " ";
        }
        else
        {
            cout << -*nums2.begin() << " ";
        }
        
    }
 
    cout << endl;
    return 0;
}
