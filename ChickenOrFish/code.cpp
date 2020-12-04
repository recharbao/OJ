
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
    for(int j = 0; j< t; j++)
    {
        int m, k;
        cin >> m >> k;
        vector<int> dish;
        for(int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            dish.push_back(x);
        }

        vector<vector<int> > nums;
        for(int i = 0; i < m - 1; i++)
        {
            int t, r;
            cin >> t >> r;
            vector<int> tmp;
            tmp.push_back(t);
            tmp.push_back(r);
            nums.push_back(tmp);
        }


        int count = 0;
        int IX = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i][1] == 1)
            {
                IX = i;
                break;
            }
            if(nums[i][0] == 0)
            {
                count++;
                continue;
            }
            int index = nums[i][0] - 1;
            dish[index]--;
        }

        vector<int> visited(dish.size(), 0);
        vector<int> judge(dish.size(), 0);
        for(int i = IX; i < nums.size(); i++)
            if(nums[i][0] != 0)
                visited[nums[i][0] - 1] = 1;

        int MINIndex = -1;
        for(int i = 0; i < dish.size(); i++)
            if(visited[i] == 0 && (MINIndex == -1 || dish[MINIndex] > dish[i])) MINIndex = i;

        if(IX < nums.size())
        {
            int MINVal = dish[MINIndex];
            for(int i = 0; i < dish.size(); i++)
            {
                if (visited[i] == 0 && count - dish[i] >= 0) judge[i] = 1;
                if (visited[i] == 0 && MINVal == dish[i]) dish[i] = 0;
            }
            count -= MINVal;
        }

        for(int i = IX; i < nums.size(); i++)
        {
            if(nums[i][0] == 0)
            {
                count++;
                continue;
            }

            dish[nums[i][0] - 1]--;
        }

        string res = "";
        for(int i = 0; i < dish.size(); i++)
        {
            if(dish[i] <= count || judge[i] == 1) res += "Y";
            else
                res += "N";
        }
        ans.push_back(res);
    }

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}




/*
1

3 4
2 3 2 1
1 0
0 0

1
5 5
1 2 1 3 1
3 0
0 0
2 1
4 0

1
3 3
1 1 1
0 0
1 1



1
4 4
1 3 2 2
0 0
0 1
0 0





*/
