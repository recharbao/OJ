#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
vector<vector<int>> kClosest(vector<vector<int>>& points, int K);


int main()
{
    vector<vector<int>> points{{-5,4},{-6,-5},{4,6}};

    int K=2;
    vector<vector<int>>result;
    result=kClosest(points,K);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<result[i][j];
        }
        cout<<endl;
    }
    return 0;
}

static bool cmp(vector<int> a,vector<int> b)
{
    int x=a[2];
    int y=b[2];
    return x<y;
}



vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    
    vector<vector<int>> result(K);
    for(int i=0;i<points.size();i++)
    {
        int tmp=pow(points[i][0],2)+pow(points[i][1],2);
        points[i].push_back(tmp);
    }

        sort(points.begin(),points.end(),cmp);
    for(int i=0;i<K;i++)
    {
        result[i].push_back(points[i][0]);
        result[i].push_back(points[i][1]);
    }

    return result;


    }



    //·ÖÖÎ·¨



    
class Solution {
public:
    int dist(vector<int>& point) {
        return pow(point[0], 2) + pow(point[1], 2);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int left = 0, right = points.size()-1;
        vector<vector<int>> res;
        while (true) {
            int pos = partition(points, left, right);
            if (pos == K-1) {
                for (int i=0; i<K; i++)
                    res.push_back(points[i]);
                return res;
            } else if (pos > K-1) right = pos-1;
            else left = pos+1;
        }
    }
    
    int partition (vector<vector<int>>& points, int left, int right) {
        int pivot = dist(points[left]), l = left+1, r = right;
        while (l <= r) {
            if (dist(points[l]) > pivot && dist(points[r]) < pivot)
                swap(points[l++], points[r--]);
            if (dist(points[l]) <= pivot) l++;
            if (dist(points[r]) >= pivot) r--;
        }
        swap(points[left], points[r]);
        return r;
    }
};



static auto x = []() { std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;}();

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), [](vector<int> &a, vector<int> &b) {return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];	});
		points.resize(K);
		return points;
    }
};



struct cmp{
    cmp(){}
    bool operator()(const vector<int>& A,const vector<int>& B)const{
        return (A[0]*A[0] + A[1]*A[1]) < (B[0]*B[0] + B[1]*B[1]);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),cmp());
        vector<vector<int>> ans(points.begin(),points.begin()+K);
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        bqs(points,0,points.size()-1,K);
        vector<vector<int>> res;
        for(int i=0;i<K;i++)
            res.push_back(points[i]);
        return res;
    }
    void bqs(vector<vector<int>>& points,int left,int right,int k)
    {
        if(left >= right) return;
        int pivot = distance(points[left]);
        vector<int> temp = points[left];
        int l = left; 
        int r = right;
        while(l < r)
        {
            while(l < r && distance(points[r]) >= pivot) 
                r--; 
            if(l<r)
                points[l++] = points[r];
            while(l < r && distance(points[l]) <= pivot) 
                l++;
            if(l<r)
                points[r--] = points[l];
        }
        points[l] = temp;
        if(l-left+1>k) bqs(points,left,l-1,k);
        else if(l-left+1<k) bqs(points,l+1,right,k-(l-left+1));
        else return;
    }
    int distance(vector<int>& point)
    {
        return point[0]*point[0]+point[1]*point[1];
    }
};





#define MAXN ((int)1e5+7)
struct Node {
    int c2, a, b;
    Node(int _a=0, int _b=0) : a(_a), b(_b) { c2 = _a*_a + _b*_b; }
    bool operator < (const Node& y) const { return c2 > y.c2; }
} node[MAXN];

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int K) {
        int n = arr.size();
        priority_queue<Node> heap;
        for(int i=0; i<n; i++) {
            heap.push(Node(arr[i][0], arr[i][1]));
        }
        // for(int i=0; i<n; i++)
        //     node[i] = Node(arr[i][0], arr[i][1]);
        // sort(node, node+n);
        vector<vector<int> > ans;
        // for(int i=0; i<K; i++) ans.push_back({node[i].a, node[i].b});
        while(K--) {
            ans.push_back({heap.top().a, heap.top().b});
            heap.pop();
        }
        return ans;
    }
};



class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        vector<int> subans(2);
        int n=points.size();
        N t[n+1];
        for(int i=0;i<n;i++)
        {
            t[i].i=i;
            t[i].dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
        }
        sort(t,t+n,cmp);
        for(int i=0;i<K;i++){
            subans[0]=points[t[i].i][0];
            subans[1]=points[t[i].i][1];
            ans.push_back(subans);
        }
        return ans;
    }
private:
    
    struct N{
        int dis,i;
    };
    
    static bool cmp(N a,N b){
        return a.dis<b.dis;
    }
};




class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        vector<int> subans(2);
        int n=points.size();
        N t[n+1];
        for(int i=0;i<n;i++)
        {
            t[i].i=i;
            t[i].dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
        }
        sort(t,t+n,cmp);
        for(int i=0;i<K;i++){
            subans[0]=points[t[i].i][0];
            subans[1]=points[t[i].i][1];
            ans.push_back(subans);
        }
        return ans;
    }
private:
    
    struct N{
        int dis,i;
    };
    
    static bool cmp(N a,N b){
        return a.dis<b.dis;
    }
};