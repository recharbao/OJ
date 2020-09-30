#include<iostream>
#include<vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    int count,n,tmp;
    cin >> count;
    while (count-- > 0)
    {
        vector<int> a;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        //查看最大堆
        int maxPile = *max_element(a.begin(), a.end());
        //求和
        int sumPile = accumulate(a.begin(), a.end(), 0);

        //无法证明，但就是对的
        if (maxPile * 2 > sumPile || sumPile & 1) //奇数
        {
            cout << "T" << endl;
        }
        else
        {
            cout << "HL" << endl;
        }
        
        
    }
    
    return 0;
}


