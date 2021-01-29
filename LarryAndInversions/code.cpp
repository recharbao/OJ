#include<bits/stdc++.h>
#include<vector>
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
    vector<vector<int> > sum(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] > nums[j])
            {
                tmp++;
            }
            sum[i][j] = tmp;
        }
        count += tmp;

    }

    string res = "";
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(i == j)
            {
                res += to_string(count) + " ";
            }
            else
            {
                int tmp = 0;
                for(int k = i; k < j; k++)
                {
                    tmp += sum[k][j];
                }
                res += to_string(count + (j - i + 1) * (j - i) / 2 - 2 * tmp) + " ";
            }
            
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
