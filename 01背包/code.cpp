#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int beg01(vector<int>weight,vector<int>value,int carrweigh);

int main()
{
    vector<int>weight{0,2,3,4,5,9}; 
    vector<int>value{0,3,4,5,6,10};
    int carrweigh=20;
    int result;
    result=beg01(weight,value,carrweigh);
    cout<<result;
    return 0;
}




int beg01(vector<int>weight,vector<int>value,int carrweigh)
{
    int nums=weight.size();
    weight.insert(weight.begin(),0);
    value.insert(value.begin(),0);              //«∞√Ê—π¡„£ª
    vector<vector<int>> F(nums+1,vector<int>(carrweigh+1,0));
    for(int i=1;i<nums+1;i++)
    {
        cout<<"i="<<i<<endl;
        for(int j=1;j<carrweigh+1;j++)
        {
            if(j<weight[i])
            {
                F[i][j]=F[i-1][j];
            }
            else
            {
                F[i][j]=max(F[i-1][j],F[i-1][j-weight[i]]+value[i]);
            }

            cout<<"F["<<i<<"]["<<j<<"]="<<F[i][j]<<endl;
        }
    }
    return F[nums][carrweigh];
}


