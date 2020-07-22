#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int carFleet(int target, vector<int>& position, vector<int>& speed);
int main()
{
    int target = 12;
    int result;
    vector<int> position{10,8,0,5,3};
    vector<int> speed{2,4,1,1,3};
    result=carFleet(target,position,speed);
    cout<<result;
    return 0;
}

static bool cmp(vector<double> a,vector<double> b)
{
    int x = a[0];
    int y = b[0];
    return x > y;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) 
{
    int count=0;
    int nums = position.size();
    if(nums == 0) return 0;
    vector<vector<double>> merge(nums,vector<double>(2,0));
    for(int i = 0;i < nums;i++)
    {
        merge[i][0] = position[i];
        merge[i][1] = speed[i];
    }
    sort(merge.begin(),merge.end(),cmp);

    double time[nums];
    for(int i = 0;i < nums;i++)
    {
        time[i] = (target - merge[i][0]) / merge[i][1];
    }

    int i=0;
    while (i < nums)
    {
        int j = i;
        while (j < nums && time[i] >= time[j])
        {
            j++;
        }
        count++;
        i = j;
    }

    return count;
    
}




