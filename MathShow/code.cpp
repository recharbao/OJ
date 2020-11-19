#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    int n, k ,M;
    cin >> n >> k >> M;
    vector<int> task;
    vector<int> nums;
    for(int i = 0, x; i < k; i++)
    {
        cin >> x;
        task.push_back(x);
    }

    sort(task.begin(), task.end());

    int remainder = M;
    for(int i = 0; i < k; i++)
    {
        int tmp = min(remainder/task[i], n);
        nums.push_back(tmp);
        remainder -= tmp * task[i];
    }

    int medium = k - 1;
    int last = nums[k - 1];

    while (medium >= 0)
    {
        while (medium >= 0 && nums[medium] <= last + 1) medium--;

        if (medium < 0) break;
        
        last++;
    
        int needTime = 0;
        int pointMov = 0;
        for (int i = k - 1; i > medium ; i--)
        {
            needTime += last > nums[i] ? task[i] : 0;
            pointMov += last > nums[i] ? 1 : 0;
        }

        int sum = 0;
        for(int j = medium; j >= 0; j--)
        {
            sum += task[j] * (nums[j] - last);
            if (sum + remainder >= needTime) break;
        }
    
        if (sum + remainder >= needTime)
        {
            for (int i = k - 1; i > medium ; i--)
                nums[i] += last > nums[i] ? 1 : 0;

            sum = 0;
            for (int j = pointMov; j >= 0; j--)
            {
                nums[medium]--;
                sum += task[medium];
                if(sum + remainder >= needTime) break;
                if (nums[medium] <= last) medium--;
            }

            remainder += sum - needTime;
        }
    }

    cout << accumulate(nums.begin(), nums.end(), 0) + nums[k - 1] << endl;

    return 0;
}

















/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool dfs(vector<int>& task, vector<int>& nums, int cur, int remainder, bool flag = false);

int main()
{
    int n, k ,M;
    cin >> n >> k >> M;
    vector<int> task;
    vector<int> nums;
    for(int i = 0, x; i < k; i++)
    {
        cin >> x;
        task.push_back(x);
    }

    sort(task.begin(), task.end());

    int remainder = M;
    for(int i = 0; i < k; i++)
    {
        int tmp = min(remainder/task[i], n);
        nums.push_back(tmp);
        remainder -= tmp * task[i];
    }

    int medium = k - 1;
    int last = nums[k - 1];

    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;


    while (medium >= 0)
    {
        cout << "mediumPre = " << medium << endl;
        while (medium >= 0 && nums[medium] <= last + 1)
        {
            medium--;
        }
        if (medium < 0)
        {
            break;
        }
        
        cout << "mediumSuff = " << medium << endl;
        last++;
        cout << "last = " << last << endl;
        int needTime = 0;
        int pointMov = 0;
        for (int i = k - 1; i > medium ; i--)
        {
            needTime += (last - nums[i]) > 0 ? task[i] : 0;
            pointMov += (last - nums[i]) > 0 ? 1 : 0;
        }

        cout << "needTime = " << needTime << endl;

        int sum = 0;
        for(int j = medium; j >= 0; j--)
        {
            sum += task[j] * (nums[j] - last);
            if (sum + remainder >= needTime)
            {
                break;
            }
        }
        cout << "sum = " << sum << endl;
        cout << "remaind = " << remainder << endl;

        int sum1 = 0;
        if (sum + remainder >= needTime)
        {
            for (int i = k - 1; i > medium ; i--)
            {
                nums[i] += (last - nums[i]) > 0 ? 1 : 0;
            }
            for (int j = pointMov; j >= 0; j--)
            {
                nums[medium]--;
                sum1 += task[medium];
                if(sum1 + remainder >= needTime)
                {
                    //nums[medium]++;
                    break;
                }
                cout << "last = " << last << endl;
                if (nums[medium] <= last)
                {
                    medium--;
                }
            }

            cout <<"sum1 = " << sum1 << endl;

            remainder += sum1 - needTime;

            cout << "remaind1 = " << remainder <<endl;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    cout << accumulate(nums.begin(), nums.end(), 0) + nums[k - 1] << endl;

    return 0;
}

*/







/*

5 4 40
4 2 3 3


5 4 40
2 3 3 4


9 9 2000000
1 1 1 1 1 1 1 1 1

*/


/*
#include <iostream>
#include <cstdio>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;
const int maxn = 50;
int a[maxn];
int n, k, m;

int dfs( int d, int sum ) {
    if( d > n ) return 0;
    int ans = 0;
    if( sum >= a[0] ) ans = max( ans, k+1+dfs(d+1, sum-a[0]) );
    int score = 0;
    for( int i = 1; i <= k; i++ ) {
        if( sum >= (n-d+1) * a[i] ) {
            score += (n-d+1);
            if( i == k ) score += (n-d+1);
            sum -= (n-d+1) * a[i];
        }
        else {
            score += sum / a[i];
            if( i == k ) score += sum / a[i];
            sum -= (sum/a[i])*a[i];
            break;
        }
    }
    return max(ans, score);
}
int main() {
    cin >> n >> k >> m;
    a[0] = 0;
    for( int i = 1; i <= k; i++ ) {
        cin >> a[i];
        a[0] += a[i];
    }
    sort(a+1,a+k+1);
    cout << dfs(1,m) << endl;
    return 0;
}
*/
