#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int nthUglyNumber(int n);

int main()
{
    int n;
    cin>>n;
    int result;
    result=nthUglyNumber(n);
    cout<<result;
    return 0;
}



/*class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1,1);
        int i2=0,i3=0,i5=0,i=1;
        while(i++<n){
            int tmp=min(2*res[i2],min(3*res[i3],5*res[i5]));
            res.push_back(tmp);
            if(tmp==2*res[i2]) i2++;
            if(tmp==3*res[i3]) i3++;
            if(tmp==5*res[i5]) i5++;
        }
        return res.back();
    }
};
*/

int nthUglyNumber(int n)
{
    vector<int> res(1,1);
    int i2=0,i3=0,i5=0,i=1;
    while (i<n)
    {
        int tmp=min(2*res[i2],min(3*res[i3],5*res[i5]));
        res.push_back(tmp);
        if(tmp==2*res[i2])i2++;
        if(tmp==3*res[i3])i3++;
        if(tmp==5*res[i5])i5++;
        i++;
    }
    return res.back();
}

















