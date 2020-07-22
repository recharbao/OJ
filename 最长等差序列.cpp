#include<iostream>
#include<vector>
//#include<algorithm>
#include<map>
using namespace std;

int longestArithSeqLength(vector<int>& A);

struct node
{
    int sub;
    int cnt;
    node(){}
    node(int a,int b):sub(a),cnt(b){}
};//创建一个映射；

int main()
{
    int last;
    int s[]={9,4,7,2,10};
    vector<int> A(s,s+5);
    last=longestArithSeqLength(A);
    cout<<last;
    return 0;
}

/* int longestArithSeqLength(vector<int>& A)
{
    int i,j,n,d,ans=1;
    n=A.size();
    vector<map<int,int>> count(n);
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<j;i++)
        {
            d=A[j]-A[i];
            count[j][d]=count[i][d]+1;
            ans=max(ans,count[j][d]);
        }
    }
    return ans+1;
}

*/
int longestArithSeqLength(vector<int>& A)
{
    if(A.size()<=2)return A.size();
    vector<node> an[A.size()];
    an[0].push_back(node(-1,1));
    int max=0;
    for(int i=1;i<A.size();i++)
    {
        an[i].push_back(node(-1,1));
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<an[j].size();k++)
            {
                if(an[j][k].sub==A[i]-A[j]||an[j][k].cnt==1)
                {
                    an[i].push_back(node(A[i]-A[j],an[j][k].cnt+1));
                    if(max<an[j][k].cnt+1)max=an[j][k].cnt+1;
                }
            }
        }
    }
    return max;
}










