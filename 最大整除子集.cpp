#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums);


int main()
{
    vector<int> nums{546,669};
    vector<int> result;

   result = largestDivisibleSubset(nums);

   for(int i=0;i<result.size();i++)
   {
       cout<<"result["<<i<<"]="<<result[i]<<endl;
   }
    
    return 0;
}



/*
vector<int> largestDivisibleSubset(vector<int>& nums)
{   
    vector<int> Null;

    if(nums.empty())return Null;

    sort(nums.begin(),nums.end());  

    vector<vector<int>> dp(nums.size());    

    int ans=0;
    
    int anscoor=0;
    
    dp[0].push_back(nums[0]);

    for(int i=1;i<nums.size();i++)
    {
        cout<<"i="<<i<<endl;
        int MAX=0;
        int coor;
        for(int j=i-1;j>=0;j--)
        {
            cout<<"j="<<j<<endl;
            if(nums[i]%nums[j]==0)
            {   
                if(MAX<dp[j].size())
                {
                    cout<<"dp["<<j<<"]="<<dp[j].size()<<endl;
                    MAX=dp[j].size();
                    cout<<"MAX="<<MAX<<endl;
                    coor=j;
                
                }
            }
        }
     


      if(MAX!=0)
      {
        dp[i]=dp[coor];
        dp[i].push_back(nums[i]);
        cout<<"dp="<<dp[i][1]<<endl;
        cout<<dp[i].size()<<endl;
      }

      else
      {
          vector<int> tmp;
          tmp.push_back(nums[i]);
          dp[i]=tmp;
          cout<<"dp["<<i<<"]="<<dp[i].size()<<endl;
      }

      if(ans<MAX+1)
      {
        ans=MAX+1;
        anscoor=i;
         cout<<"anscoor="<<anscoor<<endl;
        cout<<"ans="<<ans<<endl;
      }
      
     cout<<endl<<endl<<endl;
    }
    cout<<"ans="<<ans<<endl;
    cout<<"anscoor="<<anscoor<<endl;
    return dp[anscoor];
}   

*/


//设计思想
//设计程序
//编写程序






vector<int> largestDivisibleSubset(vector<int>& nums)
{   
    vector<int> Null;
    if(nums.empty())return Null;
    sort(nums.begin(),nums.end());  
    vector<vector<int>> dp(nums.size());    
    int ans=0;
    int anscoor=0;
    int M;
    dp[0].push_back(nums[0]);
    for(int i=1;i<nums.size();i++)
    {
        int MAX=0;
        int coor;
        for(int j=i-1;j>=0;j--)
        {
            if(j<ans-2)break;
            if(nums[i]%nums[j]==0)
            {   
                if(MAX<dp[j].size())
                {
                    MAX=dp[j].size();
                    coor=j;
                }
            }
        }

      if(MAX!=0)
      {
        dp[i]=dp[coor];
        dp[i].push_back(nums[i]);//已经设置初始dp的大小如果再.push_back就会从nums.size()后面加;
      }

      else
      {
          vector<int> tmp;
          tmp.push_back(nums[i]);
          dp[i]=tmp;
      }

      if(ans<MAX+1)
      {
        ans=MAX+1;
        anscoor=i;
      }
      
    }
    return dp[anscoor];
}   

