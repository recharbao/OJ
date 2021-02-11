// 该解法的时间复杂度超标，应该需要数据结构来简化时间复杂度.

#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;

bool judge(string x);

bool static cmp(vector<ll> a, vector<ll> b)
{
    return a[0] < b[0];
}


int main()
{
    int n;
    cin >> n;
    vector<ll> nums;
    ll val = INT64_MAX;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        nums.push_back(x);
        if(judge(to_string(x)) && val > x)
        {
            val = x;
        }
        
    }

    vector<vector<ll> > b;

    int pos, index;
    bool flag = true;
    
    for(int i = 0; i < n; i++)
    {
        vector<ll> tmp;
        tmp.push_back(nums[i]);
        tmp.push_back(i);
        b.push_back(tmp);
    }

    sort(b.begin(), b.end(), cmp);
    for(int i = 0; i < n; i++)
    {
        if(b[i][1] != i)
        {
            flag = false;
        }
    }
    if(!flag && val == INT64_MAX)
    {
        cout << -1 << endl;
        return 0;
    }
    if(flag)
    {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(val == b[i][0])
        {
            index = b[i][1];
            pos = i;
            break;
        }
    }


    vector<string> ans;
    for(int i = 0; i < n - 1; i++)
    {
        if(i == pos) continue;

        string res = "";
        if(index != i)
        {
            res += (to_string(i + 1) + " " + to_string(index + 1));
            swap(nums[i], nums[index]);
            index = i;
            ans.push_back(res);
        }

        ll MINID = i + 1;
        for(int j = i + 1; j < n; j++)
        {
            if(nums[MINID] > nums[j])
            {
                MINID = j;
            }
        }
        if(i > pos && nums[MINID] > nums[pos])
        {
            MINID = pos;
        }
        if(MINID < n)
        {
            res = "";
            res += (to_string(i + 1) + " " + to_string(MINID + 1));
            swap(nums[i], nums[MINID]);
            index = MINID;
            ans.push_back(res);
        }
    }

    if(pos + 1 != n && nums[pos] > nums[n - 1])
        ans.push_back(to_string(pos + 1) + " " + to_string(n));
    //cout << "n = " << n << endl;

    cout << ans.size() << endl;
    
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}






bool judge(string x)
{
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] != '4' && x[i] != '7')
        {
            return false;
        }
    }
    return true;
}


/*
7
77 66 55 44 33 22 11
1  2  3  4  5  6  7

44 66 55 77 33 22 11

11 66 55 77 33 22 44

11 44 55 77 33 22 66

11 22 55 77 33 44 66

11 22 44 77 33 55 66

11 22 33 77 44 55 66

11 22 33 77 55 44 66

*/

 
