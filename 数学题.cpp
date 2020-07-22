#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

string orderlyQueue(string S, int K);

int main()
{
    string s = "c";
    string result;
    result = orderlyQueue(s,1);
    cout<<"result = "<<result<<endl;
    return 0;
}

static bool cmp(char a,char b)
{
    return a < b;
}
string orderlyQueue(string S, int K) {
    int len = S.length();
    string tmp = S;
    if(K > 1)
    {
        sort(S.begin(),S.end(),cmp);
        return S;
    }
    else
    {
        S = S + S;
        for(int i = 0; i < len; i++)
        {
            cout<<S.substr(i,len)<<endl;
            if(tmp.compare(S.substr(i,i + len)) > 0)
            {
                
                tmp = S.substr(i,len);
            }
        }
    }
    return tmp;
}