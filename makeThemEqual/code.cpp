#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<vector<int> > nums(t);
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            nums[i].push_back(x);
        }
    }

    for(int i = 0; i < t; i++)
    {
        int sum = accumulate(nums[i].begin(), nums[i].end(), 0);
        int count = nums[i].size();
        vector<vector<int> > ans;
        if(sum % count != 0)
        {
            cout << -1 << endl;
            continue;
        }
        int average = sum / count;

        for(int j = 1; j < count; j++)
        {
            vector<int> tmp1;
            int need = ((j + 1) - nums[i][j] % (j + 1)) % (j + 1);
            tmp1.push_back(1);
            tmp1.push_back(j + 1);
            tmp1.push_back(need);
            ans.push_back(tmp1);


            vector<int> tmp2;
            tmp2.push_back(j + 1);
            tmp2.push_back(1);
            tmp2.push_back((need + nums[i][j]) / (j + 1));
            ans.push_back(tmp2);
        }

        for(int j = 1; j < count; j++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            tmp.push_back(j + 1);
            tmp.push_back(average);
            ans.push_back(tmp);
        }

        cout << ans.size() << endl;
        for(int j = 0; j < ans.size(); j++)
        {
            cout << ans[j][0] << " " << ans[j][1] << " " << ans[j][2] << " " << endl;
        }
    }
    return 0;
}





//这是一开始的思路，按道理来说，下面的解法应该是正确的，但是由于这个问题答案不唯一，有可能是pretest有问题。

/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<vector<int> > nums(t);
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            nums[i].push_back(x);
        }
    }

    for(int i = 0; i < t; i++)
    {
        int sum = accumulate(nums[i].begin(), nums[i].end(), 0);
        //cout << "sum = " << sum << endl;
        int count = nums[i].size();
        vector<vector<int> > ans;
        if(sum % count != 0)
        {
            cout << -1 << endl;
            continue;
        }
        int average = sum / count;

        for(int j = 0; j < count; j++)
        {
            nums[i][j] -= average;
        }
        for(int j = 1; j < count; j++)
        {
            if(nums[i][j] > 0 && nums[i][j] % (j + 1) != 0)
            {
                vector<int> tmp;
                int remain = (j + 1) - (nums[i][j] % (j + 1));
                nums[i][j] += remain;
                nums[i][0] -= remain;
                tmp.push_back(1);
                tmp.push_back(j + 1);
                tmp.push_back(remain);
                ans.push_back(tmp);
            }
        }
        for(int j = 1; j < count; j++)
        {
            if(nums[i][j] > 0)
            {
                vector<int> tmp;
                tmp.push_back(j + 1);
                tmp.push_back(1);
                tmp.push_back(nums[i][j] / (j + 1));
                ans.push_back(tmp);
            }
            else if(nums[i][j] < 0)
            {
                vector<int> tmp;
                tmp.push_back(1);
                tmp.push_back(j + 1);
                tmp.push_back(-nums[i][j]);
                ans.push_back(tmp);
            }
        }

        cout << ans.size() << endl;
        for(int j = 0; j < ans.size(); j++)
        {
            cout << ans[j][0] << " " << ans[j][1] << " " << ans[j][2] << endl;
        }
    }

    return 0;
}
*/

