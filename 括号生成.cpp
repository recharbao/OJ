#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
vector<string> generateParenthesis(int n);
vector<string>dfs(int left,int right,int nums,string s);
vector<string> generateParenthesis(int n);
void helper(vector<string>& ans, string tmp, int left, int right);
void dfs(const string& path, int m, int n, vector<string>* res);
int sum=0;
int main()
{
    int n=8;
    vector<string> result;
    result=generateParenthesis(n); 
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j];
        }
        cout<<endl;
    }
    cout<<"sum="<<sum<<endl;
    return 0;
}

/*

vector<string> result;
vector<string> generateParenthesis(int n)
{
    string s;
    s+='(';
    dfs(1,0,n,s);
    return result;   
}



vector<string>dfs(int left,int right,int nums,string s)
{
    if(right==nums)
    {
        result.push_back(s);
        return result;
    }

    //如果左括号的数量大于等于nums，那么只能放右括号
    if(left>=nums)
    {
        s+=')';
        dfs(left,right+1,nums,s);
    }

    else
    {
        s+='(';
        dfs(left+1,right,nums,s);

        if(left>right)
        {
            s.pop_back();
            s+=')';
            dfs(left,right+1,nums,s);
        }
    }
    s.pop_back();
    return result;
}


*/

/*
vector<string> result;
vector<string> generateParenthesis(int n)
{
    string s;
    dfs(1,0,n,s+'(');
    cout<<"sum="<<sum<<endl;
    return result;   
}



vector<string>dfs(int left,int right,int nums,string s)
{
    sum=sum+1;
    if(right==nums)
    {
        result.push_back(s);
        return result;
    }

    //如果左括号的数量大于等于nums，那么只能放右括号
    if(left>=nums)
    {
        dfs(left,right+1,nums,s+')');
    }

    else
    {
        dfs(left+1,right,nums,s+'(');

        if(left>right)
        {
            dfs(left,right+1,nums,s+')');
        }
    }
    return result;
}

*/

/*
vector<string> generateParenthesis(int n) {
		vector<string> ans;
		helper(ans, "", n, n);
		return ans;
	}
	void helper(vector<string>& ans, string tmp, int left, int right) {
        sum++;
		if (!left && !right) {
			ans.push_back(tmp);
			return;
		}
		if (left > 0) {
			helper(ans, tmp + "(", left - 1, right);
		}
		if (right > left) {
			helper(ans, tmp + ")", left, right - 1);
		}
	}
*/



 vector<string> generateParenthesis(int n) {
    vector<string> res;
        dfs("", 0, n, &res);
        return res;
    }
    
    void dfs(const string& path, int m, int n, vector<string>* res) {
        // m 表示还可以用的右括号的数量，n 表示还可以用几个左括号的数量
        sum++;
        if (m == 0 && n == 0) {
            if (!path.empty()) res->push_back(path);
            return;
        }
    
        if (n > 0) dfs(path + '(', m + 1, n - 1, res);
        if (m > 0) dfs(path + ')', m - 1, n, res);
    }
