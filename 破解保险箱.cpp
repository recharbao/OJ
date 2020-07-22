#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
#include<string>

using namespace std;

string crackSafe(int n, int k);
void dfs_comb(vector<string>& comb,int n,int k,string tmp,int cur);
bool dfs_FindPath(vector<vector<string> >& path,vector<string>& comb,int cur,int i,vector<int>& visited,string& result);

int main()
{
    int n,k;
    cout<<"put in n = "<<endl;
    cin>>n;
    cout<<"put in k = "<<endl;
    cin>>k;
    crackSafe(n,k);
    return 0;
}

string crackSafe(int n, int k)
{
    vector<string> comb;
    string tmp;
    dfs_comb(comb,n,k,tmp,0);
    vector<vector<string> > path(comb.size(),vector<string>(comb.size(),"-1"));
    vector<int> visited(comb.size(),0);
    string result = comb[0];
    visited[0] = 1;

    for(int i = 0; i < comb.size(); i++)
    {
        for(int j = 0; j < comb.size(); j++)
        {
            for(int l = 0; l < k; l++)
            {
                string tmp = comb[i];
                tmp += to_string(l);
                if(i != j && tmp.substr(1, tmp.size()) == comb[j])
                {
                    path[i][j] = to_string(l);
                    break;
                }
            }
        }
    }

    dfs_FindPath(path,comb,0,0,visited,result);

    for(int i = 0; i < comb.size(); i++)
    {
        cout<<comb[i]<<endl;
    }
    for(int i = 0; i < comb.size(); i++)
    {
       for(int j = 0; j < comb.size(); j++)
       {
           cout<<path[i][j]<<" ";
       }
       cout<<endl;
    }
    return result;
}

bool dfs_FindPath(vector<vector<string> >& path,vector<string>& comb,int cur,int i,vector<int>& visited,string& result)
{
    if(cur == comb.size())
    {
        return true;
    }
    for(int j = 0; j < path.size(); j++)
    {
        if(visited[j] == 0 && path[i][j] != "-1")
        {
            visited[j] = 1;
            result += path[i][j];
            if(dfs_FindPath(path,comb,cur + 1,j,visited,result)) return true;
            result.pop_back();
            visited[j] = 0;
        }
    }
    return false;
}


void dfs_comb(vector<string>& comb,int n,int k,string tmp,int cur)
{
    if(cur == n)
    {
        comb.push_back(tmp);
        return;
    }
    for(int i = 0; i < k; i++)
    {
        tmp += to_string(i);
        dfs_comb(comb,n,k,tmp,cur + 1);
        tmp.pop_back();
    }
}

class Solution {
public:
    string crackSafe(int n, int k)
{
    vector<string> comb;
    string tmp;
    dfs_comb(comb,n,k,tmp,0);
    vector<vector<string> > path(comb.size(),vector<string>(comb.size(),"-1"));
    vector<int> visited(comb.size(),0);
    string result = comb[0];
    visited[0] = 1;

    for(int i = 0; i < comb.size(); i++)
    {
        for(int j = 0; j < comb.size(); j++)
        {
            for(int l = 0; l < k; l++)
            {
                string tmp = comb[i];
                tmp += to_string(l);
                if(i != j && tmp.substr(1, tmp.size()) == comb[j])
                {
                    path[i][j] = to_string(l);
                    break;
                }
            }
        }
    }

    dfs_FindPath(path,comb,0,0,visited,result);
    return result;
}

bool dfs_FindPath(vector<vector<string> >& path,vector<string>& comb,int cur,int i,vector<int>& visited,string& result)
{
    if(cur == comb.size() - 1)
    {
        return true;
    }
    for(int j = 0; j < path.size(); j++)
    {
        if(visited[j] == 0 && path[i][j] != "-1")
        {
            visited[j] = 1;
            result += path[i][j];
            if(dfs_FindPath(path,comb,cur + 1,j,visited,result)) return true;
            result.pop_back();
            visited[j] = 0;
        }
    }
    return false;
}


void dfs_comb(vector<string>& comb,int n,int k,string tmp,int cur)
{
    if(cur == n)
    {
        comb.push_back(tmp);
        return;
    }
    for(int i = 0; i < k; i++)
    {
        tmp += to_string(i);
        dfs_comb(comb,n,k,tmp,cur + 1);
        tmp.pop_back();
    }
}
};