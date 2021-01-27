#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> matrix;
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        matrix.push_back(tmp);
    }

    int far = 0;
    vector<vector<int> > dp(n, vector<int>(n, 0)); //所消耗的a
    vector<vector<int> > visit(n, vector<int>(n, 0));
    visit[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = matrix[i][j] == 'a' ? 0 : 1;
            }
            else if(i == 0)
            {
                dp[i][j] = dp[i][j - 1] + (matrix[i][j] == 'a' ? 0 : 1);
            }
            else if(j == 0)
            {
                dp[i][j] = dp[i - 1][j] + (matrix[i][j] == 'a' ? 0 : 1);
            }
            else
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + (matrix[i][j] == 'a' ? 0 : 1);
            }
            
            
            if(dp[i][j] <= k)
            {
                far = max(far, i + j + 1);
                if(i < n - 1)
                {
                    visit[i + 1][j] = 1;
                }
                if (j < n - 1)
                {
                    visit[i][j + 1] = 1;
                }
            }
        }
    }

    /*
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }

    cout << "far = " << far << endl;

    */

   string ans(2 * n - 1, 'a');

   for(int tol = far; tol < 2 * n - 1; tol++)
   {
       char m = 'z';
       for(int j = 0; j < n; j++)
       {
           if((tol - j) >= 0 && (tol - j) < n && visit[tol - j][j])
           {
               m = m > matrix[tol - j][j] ? matrix[tol - j][j] : m;
           }
       }

       for(int j = 0; j < n; j++)
       {
           if((tol - j) >= 0 && (tol - j) < n && visit[tol - j][j] && matrix[tol - j][j] == m)
           {
               if(j < n - 1)
               {
                   visit[tol - j][j + 1] = 1;
               }
               if(tol - j < n - 1)
               {
                   visit[tol - j + 1][j] = 1;
               }
           }
       }
       ans[tol] = m;
   }
   
    cout << ans << endl;
    
    return 0;
}



//下面的为一开始的想法


/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;

string bfs(int i, int j, vector<string> &matrix, string s);

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<string> matrix;
    for(int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        matrix.push_back(x);
    }

    string ans;
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = k, dp[0][1] = k, dp[1][0] = k;
    int far = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dp[i - 1][j] <= 0 && dp[i][j - 1] <= 0)
            {
                dp[i][j] -= 1;
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - (matrix[i - 1][j - 1] == 'a' ? 0 : 1);
            far = max(far, i + j - 1);
        }
    }

    for(int i = 0; i < far; i++)
    {
        ans += 'a';
    }

    string tmpAns = "";


    if(far == 0)
    {
        string s;
        s = bfs(0, 0, matrix, "");
        if(tmpAns == "" || tmpAns >= s)
        {
            tmpAns = s;
        }
    }
    else
    {
        for(int i = 0; i < far; i++)
        {
            
            int j = far - i - 1;
            if(dp[i + 1][j + 1] != 0) continue;

            string s = "";
            s = bfs(i, j, matrix, "");
            if(tmpAns == "" || tmpAns >= s.substr(1, s.size() - 1))
            {
                tmpAns = s.substr(1, s.size() - 1);
            }
        }
    }
    
    
    cout << ans + tmpAns<< endl;

    return 0;
}



string bfs(int i, int j, vector<string> &matrix, string s)
{
    s += matrix[i][j];

    if(i + 1 >= matrix.size() && j + 1 >= matrix[0].size())
    {
        return s;
    }
    
    if((j + 1 < matrix[0].size()) && (i + 1 >= matrix.size() || matrix[i + 1][j] > matrix[i][j + 1]))
    {
        return bfs(i, j + 1, matrix, s);
    }
    else if(i + 1 < matrix.size() && (j +1 >= matrix[0].size()) || matrix[i + 1][j] < matrix[i][j + 1])
    {
        return bfs(i + 1, j, matrix, s);
    }
    else if(i + 1 < matrix.size() && j + 1 < matrix[0].size() && matrix[i + 1][j] == matrix[i][j + 1])
    {
        string l = bfs(i, j + 1, matrix, s);
        string k = bfs(i + 1, j, matrix, s);
        return l > k ? k : l;
    }

    return s;
}
*/


