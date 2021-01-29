#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(nums[i] > nums[j]) count++;
    



    //原本想使用一个数据结构来降低时间复杂度
    /*
    vector<int> preLess(n, 0);
    vector<int> suffGreat(n, 0);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i]) preLess[i]++;
            if(nums[n - j - 1] > nums[n - i - 1]) suffGreat[n - i - 1]++;
        }
    }
    */


    string res = "";
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int x = 0;
            if(j > i)
            {
                for(int k = i + 1; k < j; k++)
                {
                    if(nums[k] > nums[i] && nums[k] < nums[j])
                    {
                        x++;
                    }
                }
            }
            if(i == j)
                res += to_string(count) + " ";
            else if(nums[i] < nums[j])
                res += to_string(count + 2 * x + 1) + " ";
            else
                res += to_string(count - 2 * x - 1) + " ";
        }
    }

    res.erase(res.size() - 1);

    cout << res << endl;

    return 0;
}

/*

15
4 7 1 2 3 13 6 5 9 8 15 11 12 10 14

*/
