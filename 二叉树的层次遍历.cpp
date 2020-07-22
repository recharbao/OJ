#include<iostream>
#include<vector>
#include<stdlib.h>
#include<queue>
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}BTNode;


void CreateNode(BTNode *&b,vector<int> S,int i)
{
    if(b!=NULL)
    {
        
        b=(BTNode*)malloc(sizeof(BTNode));
        b->data=S[i];
        cout<<"S["<<i<<"]="<<S[i]<<endl;
        if(S[i+1]!=0)
            CreateNode(b->lchild,S,i+1);
        else
            b->lchild=NULL;
        if(S[i+2]!=0)
            CreateNode(b->rchild,S,i+2);
        else
            b->rchild=NULL;
    }
}



void CoutNode(BTNode *&b)
{
    if(b!=NULL)
    {   
        cout<<b->data;
        CoutNode(b->lchild);
        CoutNode(b->rchild);
    }
}




int main()
{
    BTNode *b;
    vector<int> S{1,2,0,4,5,6};
    b=(BTNode*)malloc(sizeof(BTNode));
    CreateNode(b,S,0);
    CoutNode(b);
    return 0;
}


/*
vector<vector<int>> levelOrder(BTNode* root)
{
    queue<BTNode> p;
    BTNode *q;
    while (!p.empty())
    {
        q=p.front();
        p.pop();
         cout<<q
    }
    
}

*/






