#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMinMoves(vector<int>& machines);
int main()
{
    vector<int> machines{1,2,3,4,5};
    findMinMoves(machines);
    return 0;
}

int findMinMoves(vector<int>& machines)
{
    int sum = 0;
    for(int i = 0; i < machines.size(); i++)
    {
        sum += machines[i];
    }

    int target = sum / machines.size();
    int diff = 0;
    int res = INT_MIN;
    for(int i = 0; i < machines.size(); i++)
    {
         diff += machines[i] - target;
         res = max(res,max(machines[i] - target,diff));
    }
    return res;
}
