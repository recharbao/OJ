class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int MAX = 0;
        vector<string> ans;
        string tmp;
         if(s.size()==0)
         {
            ans.push_back(tmp);
            return ans;
         }
        dfs(s,0,s.size(),0,0,tmp);

        map<string,int> count;
        map<string,int>:: iterator it;

        for(int i = 0;i < res.size();i++)
            MAX = max(count[res[i]] = res[i].size(),MAX);

        for(it = count.begin();it!=count.end();++it)
            if(it->second == MAX)
                ans.push_back(it->first);

        return ans;
    }
    void dfs(string s,int cur,int n,int left,int right,string tmp)
    {
        if(cur >= n && left == right)
            res.push_back(tmp);
        else if(cur < n)
        {
            if(left == right)
            {
                res.push_back(tmp);
              while(cur < n)
              {
                  if(s[cur] != ')')
                  {
                      tmp += s[cur];
                      if(s[cur] == '(')
                      {
                          dfs(s,cur + 1,n,left + 1,right,tmp);
                          tmp.pop_back();
                      }
                      else
                        res.push_back(tmp);
                  }
                  cur ++;
              }
            }
            else if(left > right)
            {
                while(cur < n)
                {
                    tmp += s[cur];
                    if(s[cur] == '(')
                        dfs(s,cur + 1,n,left + 1,right,tmp);
                    else if(s[cur] == ')')
                        dfs(s,cur + 1,n,left,right + 1,tmp);
                    if(s[cur] == '('||s[cur] == ')')
                        tmp.pop_back();
                    cur ++;
                }
            }
        }
    }

};