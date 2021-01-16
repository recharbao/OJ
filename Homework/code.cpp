#include<iostream>
#include<vector>
using namespace std;


void dfs(int x, int y, int cnt);
int n, m, k, curTol, tol;
bool flag = false;
int nums[33340][320];
int middleAns[33340][320];
vector<vector<string> > ans;
int main()
{
	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		cin >> n >> m >> k;
		tol = 8 * m * n;
		curTol = 0;
		flag = false;
		bool ex = false;
		if(n < m) 
		{
			swap(n, m);
			ex = true;
		}
		dfs(1, 1, 0);
		string res = "";
		vector<string> tmp;
		if(!flag)
		{
			res += "-1";
			tmp.push_back(res);
			ans.push_back(tmp);
		}
		else if(!ex)
		{
			for (int i = 1; i <= n; i++)
			{
				res = "";
				
				for(int j = 1; j <= m; j++)
				{
					res += middleAns[i][j] == 1 ? '*' : '.';
				}
				tmp.push_back(res);
			}

			ans.push_back(tmp);
		}
		else
		{
			for (int i = 1; i <= m; i++)
			{
				res = "";
				
				for(int j = 1; j <= n; j++)
				{
					res += middleAns[j][i] == 1 ? '*' : '.';
				}
				tmp.push_back(res);
			}

			ans.push_back(tmp);
		}
		
	}

	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}


	return 0;
}

void dfs(int x, int y, int cnt)
{
	if(flag) return;
	//不可没有*
	if((x != 1 || y != 1) && cnt == k)
	{
		flag = true;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				middleAns[i][j] = nums[i][j];
			}
		}

		return;
	}

	if(x > n) return;
	if(y > m) return dfs(x + 1, 1, cnt);

	//找到一种图案返回
	if(++curTol > tol) return;

	//与周围的12个关系
	int add = 0;
	add += nums[x-1][y] && nums[x][y+1];
	add += nums[x][y+1] && nums[x+1][y];
	add += nums[x+1][y] && nums[x][y-1];
	add += nums[x][y-1] && nums[x-1][y];
	add += nums[x][y-1] && nums[x-1][y-1];
	add += nums[x-1][y] && nums[x-1][y-1];
	add += nums[x][y+1] && nums[x-1][y+1];
	add += nums[x-1][y] && nums[x-1][y+1];
	add += nums[x][y-1] && nums[x+1][y-1];
	add += nums[x+1][y] && nums[x+1][y-1];
	add += nums[x][y+1] && nums[x+1][y+1];
	add += nums[x+1][y] && nums[x+1][y+1];

	if(cnt + add <= k)
	{
		if(x == 1 || y == 1 || nums[x - 1][y] || nums[x][y - 1])
		{
			nums[x][y] = 1;
			dfs(x, y + 1, cnt + add);
			nums[x][y] = 0;
		}
	}

	dfs(x, y + 1, cnt);
}



