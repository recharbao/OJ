#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int  main()
{
    int n;
    cin >> n;
    vector<vector<int> > nums(n, vector<int>(n, 0));

    for(int s = 1; s < n; s++)
        for(int j = s; j >= 0; j--)
            if((s - j) != j) nums[s - j][j] = s;

    for(int s = n; s < (2 * n - 4); s++)
        for(int i = n - 2; i >= (s - (n - 2)); i--)
            if(i != (s - i)) nums[i][s - i] = (s - (n - 1));

    for(int i = 1; i < (n - 1); i++)
    {
        if(i < n / 2)
        {
            nums[n - 1][i] = 2 * i;
            nums[i][n - 1] = 2 * i;
        }
        else
        {
            nums[n - 1][i] = 2 * (i - n / 2 + 1) - 1;
            nums[i][n - 1] = 2 * (i - n / 2 + 1) - 1;
        }
        
        
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
