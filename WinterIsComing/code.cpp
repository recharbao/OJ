#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x >= 0 ? 1 : -1);
    }

    nums.push_back(-nums[nums.size() - 1]);
    vector<int> days;
    int cnt = 1;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == nums[i + 1]) cnt++;
        else
        {
            days.push_back(nums[i] >= 0 ? cnt : -cnt);
            cnt = 1;
        }
    }
    
    if(days[0] > 0) days.erase(days.begin());

    int winDays = 0;
    int res = days.size() == 0 ? 0 : 1;
    for(int i = 0; i < days.size(); i += 2) winDays += days[i];

    if((k += winDays) < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> summer;
    for(int i = 1; i < days.size(); i += 2)
        if(i != days.size() - 1 || (i == days.size() - 1 && days[i] < 0)) summer.push_back(days[i]);

    sort(summer.begin(), summer.end());
    int index = summer.size();
    
    for(int i = 0; i < summer.size(); i++)
    {
        if(k >= summer[i]) k -= summer[i];
        else
        {
            index = i;
            break;
        }
    }

    if(days.size() != 0 && days[days.size() - 1] >= 0 && k < days[days.size() - 1]) res  += 1;

    cout << res + 2 * (summer.size() - index) << endl;

    return 0;
}



/*

8 3
5 5 5 5 5 5 5 5

*/
