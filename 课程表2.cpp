#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);


int main()
{
    int numCourses=4;
    vector<vector<int>> prerequisites {{1,0},{2,0},{3,1},{3,2}};
    vector<int> result;
    result=findOrder(numCourses,prerequisites);
    for(int i=0;i<result.size();i++)
    {
        cout<<"result="<<result[i];
    }
    return 0;
}


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    int count;
    vector<int> order;
    vector<vector<int>> graph(numCourses,vector<int>(0));
    vector<int> degree(numCourses,0);
    queue<int> zero;

    for(int i=0;i<prerequisites.size();i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        degree[prerequisites[i][0]]++;
    }

    for(int i=0;i<numCourses;i++)
    {
        if(degree[i]==0)
        {
            zero.push(i);
        }
    }

    while (!zero.empty())
    {
        int point=zero.front();
        zero.pop();
        order.push_back(point);
        count++;
        for(int i=0;i<graph[point].size();i++)
        {
            degree[graph[point][i]]--;
            if(degree[graph[point][i]]==0)
            {
                zero.push(graph[point][i]);
            }
        }
    }

    if(count==numCourses) return order;

    return {};
}



/*
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> degree(numCourses, 0);
        queue<int> zero;
        for (int i = 0;i < prerequisites.size();i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        for (int i = 0;i < numCourses;i++) {
            if (degree[i] == 0)
                zero.push(i);
        }
        int count = 0;
        while (!zero.empty()) {
            int point = zero.front();
            zero.pop();
            order.push_back(point);
            count++;
            for (int i = 0;i < graph[point].size();i++) {
                degree[graph[point][i]]--;
                if (degree[graph[point][i]] == 0)
                    zero.push(graph[point][i]);
            }
        }
        if (count == numCourses) return order;
        return {};
    }


*/







/*
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> visit(numCourses,0);
    vector<int>result;
    vector<int>result1;
    int count=0;
    while (count<numCourses)
    {
        count++;
        for(int i=0;i<numCourses;i++)
        {
            //cout<<"count="<<count<<endl;
            //cout<<"i="<<i<<endl;
            //cout<<"visit["<<i<<"]="<<visit[i]<<endl;
            if(visit[i]==0)
            {
                //cout<<i<<endl;
                bool ok=true;
                for(int j=0;j<prerequisites.size();j++)
                {
                    if(prerequisites[j][0]==i)
                    {
                        ok=false;
                    }
                }
                if(ok)
                {
                   for(int j=0;j<prerequisites.size();j++)
                   {
                       if(prerequisites[j][1]==i)
                       {
                           prerequisites[j][0]=-1;
                       }
                   }
                    visit[i]=1;
                    result.push_back(i);
                }
            }
        }
    }
    for(int i=0;i<visit.size();i++)
    {
        if(visit[i]==0)
            return  result1;
    }
    //cout<<"because";
    return result;
}


*/


/*

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> visit(numCourses,0);
    vector<int>result;
    vector<int>result1;
    
    int count=0;
    while (count<numCourses)
    {
        count++;
        for(int i=0;i<numCourses;i++)
        {
            //cout<<"count="<<count<<endl;
            //cout<<"i="<<i<<endl;
            //cout<<"visit["<<i<<"]="<<visit[i]<<endl;
            if(visit[i]==0)
            {
                //cout<<i<<endl;
                bool ok=true;
                for(int j=0;j<prerequisites.size();j++)
                {
                    if(prerequisites[j][0]==i)
                    {
                        ok=false;
                    }
                }
                if(ok)
                {
                   for(int j=0;j<prerequisites.size();j++)
                   {
                       cout<<prerequisites.size()<<endl;
                       if(prerequisites[j][1]==i)
                       {
                           cout<<prerequisites.size()<<endl;
                           //prerequisites[j][0]=-1;
                           //prerequisites[j][1]=-1;
                           prerequisites.erase(prerequisites.begin()+j,prerequisites.begin()+j+1);
                           j--;
                       }
                   }
                    visit[i]=1;
                    result.push_back(i);
                }
            }
        }
    }
    for(int i=0;i<visit.size();i++)
    {
        if(visit[i]==0)
            return  result1;
    }
    //cout<<"because";
    return result;
}
*/




/*
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> visit(numCourses,0);
    vector<int>result;
    vector<int>result1;
    list<vector<int>> tmp;
    for(int i=0;i<prerequisites.size();i++)
        tmp.push_back(prerequisites[i]);
    
    int count=0;
    while (count<numCourses)
    {
        count++;
        for(int i=0;i<numCourses;i++)
        {
            if(visit[i]==0)
            {
                bool ok=true;
                for(list<vector<int>>::iterator iter=tmp.begin();iter!=tmp.end();++iter)
                {
                    if(*(iter->begin())==i)
                    {
                        ok=false;
                    }
                }
                if(ok)
                {
                    for(list<vector<int>>::iterator iter=tmp.begin();iter!=tmp.end();)
                    {
                        list<vector<int>>::iterator iter1;
                        if(*(iter->begin()+1)==i)
                        {
                            iter1=iter;
                            ++iter;
                            tmp.erase(iter1);//注意节点删除的影响2
                        }
                        else
                        {
                            ++iter;//注意if外面也要+；
                        }
                        
                    }
                    visit[i]=1;
                    result.push_back(i);
                }
            }
        }
    }
    for(int i=0;i<visit.size();i++)
    {
        if(visit[i]==0)
            return  result1;
    }
    //cout<<"because";
    return result;
}
*/




/*
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> visit(numCourses,0);
    vector<int>result;
    vector<int>result1;
    vector<int> tmp1;
    vector<int> tmp2;
    int n=prerequisites.size();
    for(int i=0;i<n;i++) tmp1.push_back(prerequisites[i][0]);
    for(int i=0;i<n;i++) tmp2.push_back(prerequisites[i][1]);
    int count=0;
    while (count<numCourses)
    {
        count++;
        for(int i=0;i<numCourses;i++)
        {
            if(visit[i]==0)
            {
                bool ok=true;
                for(int j=0;j<n;j++)
                {
                    if(tmp1[j]==i)
                    {
                        ok=false;
                        break;
                    }
                }
                if(ok)
                {
                   for(int j=0;j<n;j++)
                   {
                       if(tmp2[j]==i)
                       {
                           tmp1[j]=-1;
                       }
                   }
                    visit[i]=1;
                    result.push_back(i);
                }
            }
        }
    }
    for(int i=0;i<visit.size();i++)
    {
        if(visit[i]==0)
            return  result1;
    }
    //cout<<"because";
    return result;
}


*/




/*
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

bool def(int numsCourses,vector<vector<int>>& prerequisites,int cur,int count[],int m);

vector<int> result;

int main()
{
    int numCourses=100;
    vector<vector<int>> prerequisites{{6,27},{83,9},{10,95},{48,67},{5,71},{18,72},{7,10},{92,4},{68,84},{6,41},{82,41},{18,54},{0,2},{1,2},{8,65},{47,85},{39,51},{13,78},{77,50},{70,56},{5,61},{26,56},{18,19},{35,49},{79,53},{40,22},{8,19},{60,56},{48,50},{20,70},{35,12},{99,85},{12,75},{2,36},{36,22},{21,15},{98,1},{34,94},{25,41},{65,17},{1,56},{43,96},{74,57},{19,62},{62,78},{50,86},{46,22},{10,13},{47,18},{20,66},{83,66},{51,47},{23,66},{87,42},{25,81},{60,81},{25,93},{35,89},{65,92},{87,39},{12,43},{75,73},{28,96},{47,55},{18,11},{29,58},{78,61},{62,75},{60,77},{13,46},{97,92},{4,64},{91,47},{58,66},{72,74},{28,17},{29,98},{53,66},{37,5},{38,12},{44,98},{24,31},{68,23},{86,52},{79,49},{32,25},{90,18},{16,57},{60,74},{81,73},{26,10},{54,26},{57,58},{46,47},{66,54},{52,25},{62,91},{6,72},{81,72},{50,35},{59,87},{21,3},{4,92},{70,12},{48,4},{9,23},{52,55},{43,59},{49,26},{25,90},{52,0},{55,8},{7,23},{97,41},{0,40},{69,47},{73,68},{10,6},{47,9},{64,24},{95,93},{79,66},{77,21},{80,69},{85,5},{24,48},{74,31},{80,76},{81,27},{71,94},{47,82},{3,24},{66,61},{52,13},{18,38},{1,35},{32,78},{7,58},{26,58},{64,47},{60,6},{62,5},{5,22},{60,54},{49,40},{11,56},{19,85},{65,58},{88,44},{86,58}};

    findOrder(numCourses,prerequisites);
    for(int i=0;i<result.size();i++)
        cout<<"result"<<"["<<i<<"]"<<"="<<result[i]<<endl;
    return 0;
}



vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    //初始化
    int sum=0;
    int n=prerequisites.size();
    //vector<int> over;
    for(int i=0;i<numCourses;i++)
    {
        vector<int> a;
        int ok=1;
        for(int j=0;j<prerequisites.size();j++)
        {
            if(prerequisites[j][1]==i)
                ok=0;
        }

        if(ok)
        {
            sum++;
            a.push_back(i);
            a.push_back(-1);
            prerequisites.push_back(a);
        }
    }

    if(!sum)
    {
        return result;
    }


    
//
    int count[numCourses];
//数组初始化

    for(int i=0;i<numCourses;i++)
    {
        count[i]=1;
    }
    def(numCourses,prerequisites,prerequisites[n][0],count,0);
    return result;
}


//两个数组排序


bool def(int numsCourses,vector<vector<int>>& prerequisites,int cur,int count[],int m)
{
    //涂黑
    for(int i=0;i<numsCourses;i++)cout<<"count"<<"["<<i<<"]"<<"="<<count[i]<<endl;
   // cout<<"m="<<m<<endl;
    if(m==numsCourses)return true;
    else
    {
        for(int i=0;i<prerequisites.size();i++)
            if(prerequisites[i][1]==cur)
                prerequisites[i][1]=-1;

    //for(int i=0;i<numsCourses;i++)cout<<"prerequisites"<<"["<<i<<"]"<<"="<<prerequisites[i][1]<<endl;

        for(int i=0;i<numsCourses;i++)
        {
            if(count[i]==1)
            {
                int ok=1;
                for(int j=0;j<prerequisites.size();j++)
                    if(prerequisites[j][0]==i&&prerequisites[j][1]!=-1)
                        ok=0;

                if(ok)
                {
                    count[i]=0;
                    int cur=i;
                    result.push_back(i);
                    if(def(numsCourses,prerequisites,cur,count,m+1))
                        return true;
                    count[i]=1;
                    result.pop_back();
                }
            }
        }
    }
    return false;
}
*/


