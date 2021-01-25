#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[] = {4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};

    if(n <= 11) cout << a[n - 1] << endl;
    else cout << a[10] + (n - 11) * 49 << endl;
    
    return 0;
}





/*
#include<iostream>
#include<set>
#include<vector>
#define I 1
#define V 5
#define X 10
#define L 50
using namespace std;

int Digit[4] = {I, V, X, L};
int fid(int n, set<int> &sset);
//void dfs(int s, int t, int cur, set<int> &sset);

int main()
{
    int n = 100;
    vector<int> ans;
    
    for(int i = 1; i < n; i++)
    {
        set<int> sset;
        //dfs(0, i, 1, sset);
        int res = fid(i, sset);
        ans.push_back(res);
    }

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
*/

/*
void dfs(int s, int t, int cur, set<int> &sset)
{
    if(cur > t)
    {
        if(sset.count(s) == 0)
        {
            sset.insert(s);
            cnt++;
        }
        return;
    }


    for(int i = 0; i < 4; i++)
    {
        dfs(s + Digit[i], t, cur + 1, sset);
    }
}
*/

/*
int fid(int n, set<int> &sset)
{
    int res = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k <= n; k++)
            {
                for(int l = 0; l <= n; l++)
                {
                    if((i + j + k + l) == n)
                    {
                        int m = (i * Digit[0] + j * Digit[1] + k * Digit[2] + l * Digit[3]);
                        if(sset.count(m) == 0)
                        {
                            res++;
                            sset.insert(m);
                        }
                    }
                }
            }
        }
    }
    return res;
}

*/

/*

4
10
20
35
56
83
116
155
198
244
292

*/
