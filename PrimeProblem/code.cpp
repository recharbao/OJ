#include<bits/stdc++.h>
#include<string.h>
#include<vector>
using namespace std;

//Written by Coffee. 判断素数
bool isPrime(int num)
{
	if (num == 2 || num == 3)
	{
		return true;
	}
	if (num % 6 != 1 && num % 6 != 5)
	{
		return false;
	}
	for (int i = 5; i*i <= num; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
		{
			return false;
		}
	}
	return true;
}



int main()
{
    int n;
    cin >> n;
    vector<int> res;
    bool found = false;
    if (isPrime(n))
    {
        found = true;
        res.push_back(n);
    }
    if (!found && n % 2 != 0)
    {
        if (isPrime(n - 2))
        {
            found = true;
            res.push_back(2);
            res.push_back(n - 2);
        }
        else
        {
            res.push_back(3);
            n -= 3;
        }
    }
    
    if (!found)
    {
        for(int i = 2; i < n / 2; i++)
        {
            if (isPrime(i) && isPrime(n - i))
            {
                res.push_back(i);
                res.push_back(n - i);
                break;
            }
            
        }
    }

    // for(int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
    // cout << endl;

    for(int i = 0; i < res.size(); i++)
    {
        cout << (i + 1) << " ";
    }
    
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 1; j < res[i]; j++)
        {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;

    return 0;
}
