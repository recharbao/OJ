#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<string> ans;

    for(int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums;
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        //找到k;
        bool exist = false;
        bool flag = false;

        if(nums[n - 1] == k)
        {
            if(n == 1)
                flag = true;
            exist = true;
        }

        for(int j = 0; j < n - 1; j++)
        {
            if(nums[j] >= k && (nums[j + 1] >= k || (j < n - 2 && nums[j + 2] >= k))) flag = true;
            if(nums[j] == k) exist = true;
        }
        
        if(flag && exist) 
            ans.push_back("yes");
        else
            ans.push_back("no");
    }

    for(int i = 0; i < t; i++)
        cout << ans[i] << endl;

    return 0;
}








/*
1
4 3
3 1 2 3

1
7 2
3 1 3 1 1 1 2

7
8 651748986
609388014 668036346 235867110 202018029 944584353 811232081 604677254 847266065
4 680532982
843115083 217922803 859115470 716515522
5 314873318
666660507 542201082 719718452 730924978 407807813
9 596902528
76979735 688225527 688051640 68328034 969794966 618046384 860906904 701330608 39290481
4 870229632
107489467 973422137 644764044 906767463
6 771606948
816902392 926727542 507312612 757391630 779582888 946148917
2 256856111
78695151 492789031



*/
