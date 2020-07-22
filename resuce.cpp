#include<iostream>
#include<vector>
using namespace std;

void dijkstra(vector<vector<int> >& S,int C1,int C2,int city,int rood,vector<int>& nums);

int main()
{
    int city,rood,C1,C2;
    cin>>city>>rood>>C1>>C2;
    vector<int> nums(city);
    for(int i=0;i<city;i++)
        cin>>nums[i];
    vector<vector<int> > S(rood,vector<int>(3));
    for(int i=0;i<rood;i++)
        cin>>S[i][0]>>S[i][1]>>S[i][2];
    dijkstra(S,C1,C2,city,rood,nums);
    return 0;
}

void dijkstra(vector<vector<int> >& S,int C1,int C2,int city,int rood,vector<int>& nums)
{
    int INF =0x3fffffff;
    vector<vector<int> > E(city,vector<int>(city,INF));
    vector<int> Take(city,0);//记录是否加入最短路集合
    vector<int> distance(city,INF);
    vector<int> weight(city,0);
    vector<int> sum(city,0);

    distance[C1] = 0;
    weight[C1]=nums[C1];
    sum[C1] = 1;
    for(int i=0;i<rood;i++)
    {
        int k=S[i][0];
        int l=S[i][1];
        E[k][l]=S[i][2];
        E[l][k]=S[i][2];
    }
      
    for(int times = 0; times < city; times ++)
    {
        int min=INF;
        int  j = -1;
        for(int i=0;i<city;i++)
            if(Take[i]==0 && min>distance[i])
            {
                min=distance[i];
                j=i;
            }

        if(j != -1)
        {
            Take[j]=1;
    
            for(int i=0;i<city;i++)
            {
                if(Take[i]==0 && E[j][i] < INF)
                {
                    if(distance[i]>distance[j]+E[j][i])
                    {
                        distance[i]=distance[j]+E[j][i];
                        weight[i]=weight[j]+nums[i];
                        sum[i]=sum[j];
                    }
                    else if(distance[i]==distance[j]+E[j][i])
                    {
                        sum[i] += sum[j];
                        if(weight[i]<weight[j]+nums[i])
                            weight[i]=weight[j]+nums[i];
                    }
                }
            }
        }
    }
        cout<<sum[C2]<<" "<<weight[C2];
}
