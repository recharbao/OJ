#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);    
    std::cin.tie(0);  
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        nums[x - 1] *= (-1);
    }

    stack<int> st;
    for(int i = n - 1; i >= 0; i--)
    {
        if(!st.empty() && nums[i] > 0 && abs(nums[st.top()]) == nums[i])
        {
            int topIndex = st.top();
            nums[topIndex] = -abs(nums[topIndex]);
            st.pop();
        }
        else
        {
            st.push(i);
        }
    }

    if(!st.empty())
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for(int i = 0; i < n - 1; i++)
        {
            cout << nums[i] << " ";
        }
        cout << nums[n - 1] << endl;
    }
    
    return 0;
}


