#include<iostream>
#include<algorithm>
using namespace std;
#define MAXV 5


//队列
typedef struct 
{
   int data[MAXV];
   int front,rear;
}SqQueue;


//初始化队列

void InitQueue(SqQueue *&q)
{
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=-1;
}

//销毁队列
void DestroyQueue(SqQueue *&q)
{
    free(q);
}

//判断队列是否为空
bool QueueEmpty(SqQueue *&q)
{
    return (q->front==q->rear);
}

//进队列

bool enQueue(SqQueue *&q,int e)
{
    if(q->rear==MAXV-1)
        return false;
    q->rear++;
    q->data[q->rear]=e;
    return true;
}

//出队列

bool deQueue(SqQueue *&q,int e)
{
    if(q->rear==q->front)
        return false;
    q->front++;
    e=q->data[q->front];
    return false;
}


//邻接矩阵的存储方法：
typedef struct 
{
   int no;      //顶点的编号 
}VertexType;    //顶点的类型


typedef struct 
{
    int edges[MAXV][MAXV];//邻接矩阵
    int n,e;//顶点数，边数
    VertexType vexs[MAXV];//存放顶点的信息
}MatGraph;//完整的图邻接矩阵类型

//邻接矩阵的存储方法：

typedef struct ANode
{
    int adjvex;//该点的编号；
    struct ANode *nextarc;//指向下一条边的指针；
    int weight; //边的权值
}ArcNode;//边节点的类型
typedef struct Vnode
{
    ArcNode *firstarc;
}VNode;//邻接表头节点类型
typedef struct
{
    VNode adjlist[MAXV];//头节点的集合
    int n,e;//图中顶点的个数和边的个数；
}AdjGraph;//完整的图的邻接表类型；

//创建一个图
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)
{
    int i,j;ArcNode *p;
    G=(AdjGraph *)malloc(sizeof(AdjGraph));
    for(i=0;i<n;i++)
        G->adjlist[i].firstarc=NULL;
    for(i=0;i<n;i++)
        for(j=n-1;j>=0;j--)
            if(A[i][j]!=0&&A[i][j]!=INF)
            {
                p=(ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex=j;
                p->weight;
                p->nextarc=G->adjlist[i].firstarc;//采用头插法插入；
                G->adjlist[i].firstarc=p;
            }
            G->n=n;
            G->e=e;
}




//输出邻接表
void DispAdj(AdjGraph *G)
{
    int i;ArcNode *p;
    for(int i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            cout<<p->adjvex;
            cout<<p->weight;
            p=p->nextarc;
        }
        cout<<endl;
    }
}





void DestroyAdj(AdjGraph *&G)//销毁列表
{
    int i;ArcNode *p,*pre;
    for(int i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            pre=p->nextarc;
            free(p);
            p=pre;
        }
    }
    free(G);
}

//图的遍历


//深度优先遍历

int visited[MAXV]={0};
void DFS(AdjGraph *&G,int v)
{
    ArcNode *p;
    visited[v]=1;
    cout<<v;
    p=G->adjlist[v].firstarc;
    while (p!=NULL)
    {
        if(visited[p->adjvex]==0)
            DFS(G,p->adjvex);
        p=p->nextarc;
    }
}


//广度优先遍历
void BFS(AdjGraph *G,int v)
{
    int w,i;ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    int visited[MAXV];      //做一个标记；
    for(int i=0;i<G->n;i++)visited[MAXV];//初始化为零；
    cout<<v;
    enQueue(qu,v);
    while (!(QueueEmpty(qu)))
    {
       deQueue(qu,w);//出栈；
       p=G->adjlist[w].firstarc;
       while (p!=NULL)
       {
           if(visited[p->adjvex]==0)
           {
                cout<<p->adjvex;
                enQueue(qu,p->adjvex);
                visited[p->adjvex]=1;
           }
           p=p->nextarc;
       }
    }
      cout<<endl;
}

//Dijkstra算法


void Dijkstra(MatGraph g,int v)//g是邻接矩阵q
{
    int dist[MAXV],path[MAXV];
    int S[MAXV];    //S[i]=1表示i点在S中，S[i]=0表示i点在U中;
    int MINdis,i,j,u;
    for(i=0;i<g.n;i++)//初始化;
    {
        dist[i]=g.edges[v][i]//距离初始化；
        S[i]=0;     //S[]置空；
        if(g.edges[v][i]<INF)
            path[i]=v;
        else
            path[i]=-1;
    }
    S[v]=1;
    path[v]=0;


    for(i=0;i<g.n-1;i++)//循环，直到所有顶点的最短路径都求出；
    {
        MINdis=INF;
        for(j=0;j<g.n;i++)
        {
            if(S[i]==0&&dist[j]<MINdis)
            {
                u=j;
                MINdis=dist[j];
            }
        }
        S[u]=1;
        for(j=0;j<g.n;j++)
        {
            if(S[j]==0)
                if(g.edges[u][j]<INF&&dist[u]+g.edges[u][j]<dist[j])
                {
                    dist[j]=dist[u]+g.edges[u][j];
                    path[j]=u;
                }
        }
    }
}





//输出单原最短路径;

void Dispath(MatGraph g,int dist[],int path[],int S[],int v)
{
    //输出从v点出发的所有最短路径;
    int i,j,k;
    int apath[MAXV],d;//存放一条最短路径逆向及其顶点的个数;
    for(i=0;i<g.n;i++)//循环输出从顶点v到i的路径;
        if(S[i]==1&&i!=v)
        {
            d=0;apath[d]=i;
            k=path[i];
            if(k==-1)
                cout<<"无路径"<<endl;
            else
            {
                while (k!=v)
                {
                    d++;apath[d]=k;
                    k=path[k];
                }
                d++;apath[d]=v;
                for(j=d-1;j>=0;j--)
                    cout<<apath[j];
                cout<<endl;
            }
        }
}


//prim算法
void prim(MatGraph g,int v)
{
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV],i,j,k;
    for(i=0;i<g.n;i++)
    {
        lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }
    for(i=1;i<g.n;i++)
    {
        MIN=INF;
        for(j=0;j<g.n;j++)
            if(lowcost[j]!=0&&lowcost[j]<MIN)
            {
                MIN=lowcost[j];
                k=j;
            }
        cout<<closest[k]<<","<<k<<endl;
        lowcost[k]=0;
        for(j=0;j<g.n;j++)
            if(lowcost[j]!=0&&g.edges[k][j]<lowcost[j])
            {
                lowcost[j]=g.edges[k][j];
                closest[j]=k;
            }
    }
}

typedef struct 
{
    int u;//边的始点
    int v;//边的终点
    int w;//边的权值
}Edge;



//Kruskal
void Kruskal(MatGraph g)
{
    int i,j,u1,v1,sn1,sn2,k;
    int vset[MAXV];
    Edge E[MAXV];//存放图中的边
    k=0;
    for(i=0;i<g.n;i++)
        for(j=0;j<=i;j++)
            if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
            {
                E[k].u=i;
                E[k].v=j;
                E[k].w=g.edges[i][j];
                k++;
            }
    InserSort(E,g.e);//E数组是按权值递增的顺序
    for(i=0;i<g.n;i++)//初始化辅助数组
        vset[i]=i;
    k=1;    //k表示当前构造生成树的第几条边
    j=0;    //E中的下标
    while(k<g.n)
    {
        u1=E[j].u;
        v1=E[j].v;
        sn1=vset[u1];
        sn2=vset[v1];
        if(sn1!=sn2)
        {
            cout<<"sc"<<endl;
            k++;
            for(i=0;i<g.n;i++)
                if(vset[i]==sn2)
                    vset[i]=sn1;
        }
        j++;
    }
}


//插入排序
void InserSort(Edge E,int n)
{

}

//改进的Kruskal;

