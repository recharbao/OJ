#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main()
{
    ll nums[3];
    cin >> nums[0] >> nums[1] >> nums[2];

    sort(nums, nums + 3);
    if((nums[1] - nums[0]) % 2 != 0) cout << nums[2] << endl;
    else cout << nums[1] << endl;
    
    return 0;
}
