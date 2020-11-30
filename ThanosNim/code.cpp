
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    int MIN = 100;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        MIN = min(MIN, x);
        nums.push_back(x);
    }

    int cnt = count(nums.begin(), nums.end(), MIN);
    int number = nums.size() / 2;

    if(cnt <= number)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
    
    return 0;
}




