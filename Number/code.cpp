#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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

    map<int, int> count;
    for(int i = 0; i < n; i++)
    {
        int val = nums[i];
        count[val]++;
    }

    map<int, int>::iterator it = count.begin();
    int F = it -> second;

    while(++it != count.end())
    {
        auto tmp = it--;
        int preVal = it -> first;
        it++;
        if(it -> first != (preVal + 1) || (++tmp == count.end() && F != it -> second) || (tmp != count.end() && F >= it -> second))
        {
            cout << "NO" << endl;
            return 0;
        }
        
        F = it -> second - F;
    }

    cout << "YES" << endl;

    return 0;
}



