#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll; 

int main()
{
    int t;
    cin >> t;
    vector<ll> result;
    for(int i = 0; i < t; i++)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> nums;
        for(int j = 0; j < n; j++)
        {
            ll x;
            cin >> x;
            nums.push_back(x);
        }

        ll sum = accumulate(nums.begin(), nums.end(), 0ll);
        ll left = 0, right = sum;

        //二分
        while (left < right)
        {
            ll mid = left + (right - left + 1) / 2; //偶数时在左端

            //判断是否满足条件
            ll count = 0, s = 0;
            for(int j = 0; j < n; j++)
            {
                if(s + nums[j] < mid)   s = 0;

                count += (s + nums[j]) / mid;
                s = (s + nums[j]) % mid;
            }

            if(count >= k)
                left = mid;
            else
                right = mid - 1;
        }

        result.push_back(left * k);
    }

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;


    return 0;
}


/*
1
2 1
1000000000000 1000000000000


1
2 1
1000000000 1000000000

*/
