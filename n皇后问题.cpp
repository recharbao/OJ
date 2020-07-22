#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<vector<string>> res;

bool def(int n,int i,vector<string> &S);
      

int main()
{   
    int n=1;
    //cin>>n;
    vector<string> S(n);//string不可以提前设置大小
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            S[i]=S[i]+".";
        }
        cout<<endl;
    }
    def(n,0,S);
    for(int i=0;i<res.size();i++)
    {
        cout<<i+1<<endl;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                cout<<res[i][j][k];
            }
            cout<<endl;
        }
        cout<<endl<<endl<<endl;
    }
    return 0;
}





bool def(int n,int i,vector<string> &S)
{

    if(i>=n)
    {
        res.push_back(S);
        return true;
    }

    //判断是否成立
    for(int j=0;j<n;j++)
    {
        int ok=1;

        for(int k=0;k<n;k++)
            if(k!=i&&S[k][j]=='Q')
            {
                ok=0;
                break;
            }
        if(!ok) continue;

        for(int k=0;k<n;k++)
            if(k!=i&&S[k][j]=='Q')
            {
                ok=0;
                break;
            }
        if(!ok) continue;

        int x1=i-1;
        int y1=j-1;
        while (x1>=0&&y1>=0)
        {
            if(S[x1][y1]=='Q')
            {
                ok=0;
                break;
            }
            x1--;
            y1--;
        }
        if(!ok) continue;

        int x2=i+1;
        int y2=j-1;
        while (x2<n&&y2>=0)
        {
            if(S[x2][y2]=='Q')
            {
                ok=0;
                break;
            }
            x2++;
            y2--;
        }
        if(!ok) continue;

        int x3=i-1;
        int y3=j+1;
        while (x3>=0&&y3<n)
        {
            if(S[x3][y3]=='Q')
            {
                ok=0;
                break;
            }
            x3--;
            y3++;
        }
        if(!ok) continue;

        int x4=i+1;
        int y4=j+1;
        while (x4>n&&y4>n)
        {
            if(S[x4][y4]=='Q')
            {
                ok=0;
                break;
            }
            x4++;
            y4++;
        }
        if(!ok) continue;

            S[i][j]='Q';
            def(n,i+1,S);
            S[i][j]='.';

    }
}


