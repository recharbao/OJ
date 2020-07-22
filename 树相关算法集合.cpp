#include<iostream>
using namespace std;

#define  MAXV 1000


typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}BTNode;

//销毁二叉树
void DestroyTree(BTNode *&b)
{
    if(b!=NULL)
    {
        if(b->lchild!=NULL)
            DestroyTree(b->lchild);
        if(b->rchild!=NULL)
            DestroyTree(b->rchild);
        free(b);
    }
}

//查找结点

BTNode* FindNode(BTNode *&b,int x)
{
    BTNode *p;
    if(b==NULL)
        return  NULL;
    else if (b->data==x)
    {
       return b;
    }
    
    else
    {
        p=FindNode(b->lchild,x);
        if(p!=NULL)
            return p;
        return  p=FindNode(b->rchild,x);
    }
    
}

typedef struct 
{
    BTNode *data[MAXV];
    int top;
}SqStack;

void InitStack(SqStack *&s)
{
    s=(SqStack*)malloc(sizeof(SqStack));
    s->top=-1;
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *&s)
{
    return s->top==-1;
}

bool Push(SqStack *&s,BTNode *e)
{
    if(s->top==MAXV-1)
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}

bool Pop(SqStack *&s,BTNode *e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *&s,BTNode *e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    return true;
}

void PreOrder(BTNode *&b)
{
    if(b!=NULL)
    {
        cout<<b->data;
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}


void InOrder(BTNode *&b)
{
    if(b!=NULL)
    {
        InOrder(b->rchild);
        cout<<b->data;
        InOrder(b->rchild);
    }
}


void lastOrder(BTNode *&b)
{
    if(b!=NULL)
    {
        InOrder(b->lchild);
        InOrder(b->rchild);
        cout<<b->data;
    }
}

//先序遍历的非递归算法
void PreOrder1(BTNode *&b)
{
    SqStack *st;
    BTNode *p;
    InitStack(st);
    if(b!=NULL)
    {
        Push(st,b);
        while (!StackEmpty())
        {
            Pop(st,p);
            cout<<p->data;
            if(p->lchild!=NULL)
                Push(st,p->lchild);
            if(p->rchild!=NULL)
                Push(st,p->rchild);
        }
        
    }
    DestroyStack(st);
}

void PreOrder2(BTNode *&b)
{
    SqStack *st;
    BTNode *p;
    p=b;
    while (!StackEmpty(st)||p!NULL)
    {
        while(p!=NULL)
        {
            cout<<p->data;
            Push(st,p);
            p=p->lchild;
        }
        if(!StackEmpty(st))
        {
            Pop(st,p);
            p=p->rchild;
        }
    }
     DestroyStack(st);
}

void InOrder(BTNode *&b)
{
    SqStack *st;
    BTNode *p;
    p=b;
    while (!StackEmpty(st)||p!=NULL)
    {
        while(p!=NULL)
        {
            Push(st,p);
            p=p->lchild;
        }
        if(StackEmpty(st))
        {
            cout<<p->data;
            p=p->rchild;
        }
    }
    DestroyStack(st);
    
}

void postOrder(BTNode *&b)
{
    SqStack *st;
    BTNode *p,*r;
    p=b;
    bool flag;
    do
    {
        while (p!=NULL)
        {
            Push(st,p);
            p=p->lchild;
        }
        flag=true;
        r=NULL;
        while (!StackEmpty(st)&&flag)
        {
            GetTop(st,p);
            if(p->rchild==r)
            {
                cout<<p->data;
                Pop(st,p);
                r=p;
            }
            else
            {
                p=p->rchild;
                flag=false;
            }
            
        }
        
    } while (!StackEmpty(st));
    
    DestroyStack(st);
}

typedef struct 
{
    BTNode *data[MAXV];
    int front,rear;   
}SqQueue;


void InitQueue(SqQueue *&q)
{
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=-1;
}


void DestroyQueue(SqQueue *&q)
{
    free(q);
}

bool QueueEmpty(SqQueue *&q)
{
    return q->front==q->rear;
}

bool enQueue(SqQueue *&q,BTNode *e)
{
    if(q->rear==MAXV-1)
        return false;
    q->rear++;
    q->data[q->rear]=e;
    return true;
}

bool deQueue(SqQueue *&q,BTNode *e)
{
    if(q->front==q->rear)
        return false;
    q->front++;
    e=q->data[q->front];
    return true;
}

//层次遍历
void LevelOrder(BTNode *&q)
{
    SqQueue *st;
    BTNode *p;
    p=b;
    while (!QueueEmpty(st))
    {
        deQueue(st,p);
        cout<<p->data<<endl;
        if(p->lchild!=NULL)
            enQueue(st,p);
        if(p->rchild!=NULL)
            enQueue(st,p);
    }
    DestroyQueue(st);
}

typedef struct 
{
    char data;
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNdoe;


//哈夫曼树

void CreaterHT(HTNdoe ht[],int n0)
{
    int min1,min2;
    int lnode,rnode;
    for(int i=0;i<2*n0-1;i++)
        ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
    for(int i=n0;i<2*n0-1;i++)
    {
        min1=min2=312312;
        lnode=rnode=-1;
        for(int k=0;k<i;k++)
        {
            if(ht[k].parent=-1)
            {
                if(ht[k].weight<min1)
                {
                    min2=min1;
                    min1=ht[k].weight;
                    rnode=lnode;
                    lnode=k;
                }
                else if (ht[k].weight<min2)
                {
                    min1=min2;
                    min2=ht[k].weight;
                    lnode=rnode;
                    rnode=k;
                }
                
            }
        }
    ht[i].lchild=lnode;
    ht[i].rchild=rnode;
    ht[lnode].parent=i;
    ht[rnode].parent=i;
    ht[i].weight=ht[lnode].weight+ht[rnode].weight;
    }
}