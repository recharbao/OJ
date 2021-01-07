#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    map<int, int> count;
    for(int i = 0; i < nums.size(); i++)
        count[nums[i]]++;

    vector<int> arrayNum;
    vector<int> array;
    int pre;
    for(auto it = count.begin(); it != count.end(); it++)
    {
        arrayNum.push_back(it -> first);
        array.push_back(it -> second);
    }

    int m = array.size();
    vector<ll> preSum(m + 1, 0);
    vector<ll> suffSum(m + 1, 0);
    for(int i = 1; i <= m; i++)
        preSum[i] = preSum[i - 1] + array[i - 1]; // 1 ~ n
    for(int i = m; i > 0; i--)
        suffSum[i - 1] = suffSum[i] + array[i - 1]; // n-1 ~ 0

    vector<ll> opPre(m, 0);
    vector<ll> opSuff(m, 0);
    for(int i = 1; i < m; i++)
        opPre[i] = opPre[i - 1] + preSum[i] * (arrayNum[i] - arrayNum[i - 1]);
    for(int i = m - 2; i >= 0; i--)
        opSuff[i] = opSuff[i + 1] + suffSum[i + 1] * (arrayNum[i + 1] - arrayNum[i]);

    ll MIN = INT64_MAX;
    for(int i = 0; i < m; i++)
    {
        int l = -1, r = -1;
        if(array[i] >= k)
        {
            MIN = 0;
            break;
        }
        if(preSum[i] >= (k - array[i])) l = 1;
        if(suffSum[i + 1] >= (k - array[i])) r = 1;

        if(l == -1 && r == -1) MIN = min(opPre[i] + opSuff[i] - (preSum[i] + suffSum[i + 1]) + (k - array[i]), MIN);
        else if(l != -1 && r == -1) MIN = min(opPre[i] + (k - array[i]) - preSum[i], MIN);
        else if(l == -1 && r != -1) MIN = min(opSuff[i] + (k - array[i]) - suffSum[i + 1], MIN);
        else MIN = min(min(opPre[i] + (k - array[i]) - preSum[i], opSuff[i] + (k - array[i]) - suffSum[i + 1]), MIN);
    }

    cout << MIN << endl;

    return 0;
}




/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    map<int, int> count;
    for(int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }

    vector<int> arrayNum;
    vector<int> array;
    int pre;
    for(auto it = count.begin(); it != count.end(); it++)
    {
        int y = it -> first;
        int x = it -> second;
        arrayNum.push_back(y);
        array.push_back(x);
    }

    int m = array.size();
    vector<ll> preSum(m + 1, 0);
    vector<ll> suffSum(m + 1, 0);
    for(int i = 1; i <= m; i++)
    {
        preSum[i] = preSum[i - 1] + array[i - 1]; // 1 ~ n
    }
    for(int i = m; i > 0; i--)
    {
        suffSum[i - 1] = suffSum[i] + array[i - 1]; // n-1 ~ 0
    }

    vector<ll> opPre(m, 0);
    vector<ll> opSuff(m, 0);
    for(int i = 1; i < m; i++)
    {
        opPre[i] = opPre[i - 1] + preSum[i] * (arrayNum[i] - arrayNum[i - 1]);
    }
    for(int i = m - 2; i >= 0; i--)
    {
        opSuff[i] = opSuff[i + 1] + suffSum[i + 1] * (arrayNum[i + 1] - arrayNum[i]);
    }


    //都是 0 ~ n-1
    
    for(int i = 0; i < m; i++)
    {
        cout << arrayNum[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < m; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    
    for(int i = 0; i <= m; i++)
    {
        cout << preSum[i] << " ";
    }
    cout <<endl;

    for(int i = 0; i <= m; i++)
    {
        cout << suffSum[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < m; i++)
    {
        cout << opPre[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < m; i++)
    {
        cout << opSuff[i] << " ";
    }
    cout << endl;


   ll MIN = INT64_MAX;
   for(int i = 0; i < m; i++)
   {
       int l = -1, r = -1;
       if(array[i] >= k)
       {
           MIN = 0;
           break;
       }
       if(i > 0 && (preSum[i]) >= (k - array[i])) l = 1;
       if(i < (m - 1) && (suffSum[i + 1]) >= (k - array[i])) r = 1;

       if(i > 0 && i < (m - 1) && l == -1 && r == -1)
       {
           MIN = min(opPre[i] + opSuff[i] - (preSum[i] + suffSum[i + 1]) + (k - array[i]), MIN);
       }
       else if(l != -1 && r == -1)
       {
           MIN = min(opPre[i] + (k - array[i]) - preSum[i], MIN);
       }
       else if(l == -1 && r != -1)
       {
           MIN = min(opSuff[i] + (k - array[i]) - suffSum[i + 1], MIN);
       }
       else
       {
           MIN = min(min(opPre[i] + (k - array[i]) - preSum[i], opSuff[i] + (k - array[i]) - suffSum[i + 1]), MIN);
       }
   }

   cout << MIN << endl;

    return 0;
}
*/

/*

3 3
1 5 8

*/



/*

2 2
77 99

*/



/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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
        nums.push_back(x);
    }

    map<int, int> count;
    for(int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }

    vector<int> array;
    int pre;
    for(auto it = count.begin(); it != count.end(); it++)
    {
        
        if(it != count.begin() && (pre + 1) != it -> first)
        {
            array.push_back(0);
            pre++;
            it--;
            continue;
        }

        pre = it -> first;
        int x = it -> second;
        array.push_back(x);
    }

    int m = array.size();
    vector<int> preSum(m + 1, 0);
    vector<int> suffSum(m + 1, 0);
    for(int i = 1; i <= m; i++)
    {
        preSum[i] = preSum[i - 1] + array[i - 1]; // 1 ~ n
    }
    for(int i = m; i > 0; i--)
    {
        suffSum[i - 1] = suffSum[i] + array[i - 1]; // n-1 ~ 0
    }

    vector<int> opPre(m, 0);
    vector<int> opSuff(m, 0);
    for(int i = 1; i < m; i++)
    {
        opPre[i] = opPre[i - 1] + preSum[i];
    }
    for(int i = m - 2; i >= 0; i--)
    {
        opSuff[i] = opSuff[i + 1] + suffSum[i + 1];
    }


    //都是 0 ~ n-1
    
    for(int i = 0; i < m; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    
    for(int i = 0; i <= m; i++)
    {
        cout << preSum[i] << " ";
    }
    cout <<endl;

    for(int i = 0; i <= m; i++)
    {
        cout << suffSum[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < m; i++)
    {
        cout << opPre[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < m; i++)
    {
        cout << opSuff[i] << " ";
    }
    cout << endl;
    

   int MIN = INT32_MAX;
   for(int i = 0; i < m; i++)
   {
       int l = -1, r = -1;
       if(array[i] >= k)
       {
           MIN = 0;
           break;
       }
       if(i > 0 && opPre[i - 1] >= (k - array[i]))
       {
           l = preSum[i - 1];
       }
       if(i < (m - 1) &&opSuff[i + 1] >= (k - array[i]))
       {
           r = suffSum[i + 1];
       }
       if(l == -1 && r == -1)
       {
           MIN = min(opPre[i - 1] + opSuff[i + 1] + (k - array[i]), MIN);
       }
       else if(l != -1 && r == -1)
       {
           MIN = min(opPre[i - 1] + (k - array[i]), MIN);
       }
       else if(l == -1 && r != -1)
       {
           MIN = min(opSuff[i + 1] + (k - array[i]), MIN);
       }
       else
       {
           MIN = min(min(opPre[i - 1] + (k - array[i]), opSuff[i + 1] + (k - array[i])), MIN);
       }
   }

   cout << MIN << endl;

    return 0;
}
*/

/*

19 16
1 1 1 2 2 2 2 3 3 3 3 3 3 3 4 5 5 7 8800000

*/
