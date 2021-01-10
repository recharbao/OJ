#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<string> ans;
    for(int ti = 0; ti < t; ti++)
    {
        int n, k, m;
        cin >> n >> k >> m;
        vector<int> nums;
        for(int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        vector<int> leftEraseNum(m, 0);
        vector<int> rightEraseNum(m, 0);
        for(int i = 0; i < m; i++)
            leftEraseNum[i] = nums[i] - (i + 1);
        for(int i = m - 1; i >= 0; i--)
            rightEraseNum[i] = n - nums[i] - (m - i - 1);

        string res = "NO";
        for(int i = 0; i < m; i++)
            if(leftEraseNum[i] != 0 && rightEraseNum[i] != 0 && leftEraseNum[i] >= ((k - 1) / 2) && rightEraseNum[i] >= ((k - 1) / 2) && (leftEraseNum[i] + rightEraseNum[i]) % (k - 1) == 0) res = "YES";

        ans.push_back(res);
    }

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}

/*

1
14 5 2
1 9

*/
