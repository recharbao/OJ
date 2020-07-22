#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Swap(TreeNode* a,TreeNode* b);
void recoverTree(TreeNode* root);

int main()
{
    return 0;
}
void recoverTree(TreeNode* root)
{
    stack<TreeNode*> st;
    TreeNode* Left = NULL;
    TreeNode* Right = NULL;
    TreeNode* p = root;
    TreeNode* pre = NULL;
    int countLeft = 0;
    while(p != NULL || !st.empty())
    {
        while (p != NULL)
        {
            st.push(p);
            p = p -> left;
        }

        if(!st.empty())
        {
            p = st.top();
            st.pop();

            if(pre != NULL && countLeft == 0 && pre -> val > p -> val)
            {
                countLeft = 1;
                Left = pre;
            }
            if(pre != NULL && countLeft == 1 && Left -> val < p -> val)
            {
                Right = pre;
                countLeft = -1;
            }
            pre = p;
            p = p -> right;
        }
        
    }
    if(Right == NULL) Right = pre;
    
    Swap(Left,Right);
    
}

void Swap(TreeNode* a,TreeNode* b)
{
    int tmp;
    tmp = a -> val;
    a -> val = b -> val;
    b -> val = tmp;
}

























/*
void recoverTree(TreeNode* root)
{
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* p = root;
    TreeNode* q;
    TreeNode* tmp;
    while (!st.empty())
    {
        while (p -> left != NULL)
        {
            if(p -> val > p -> left -> val)
            {
                st.push(p);
                p = p -> left;
            }
            else
            {
                q = p -> left;
                if(st.top() ->left == p)
                    st.top() -> left = q;
                else
                    st.top() -> right = q;
                p -> left = q -> left;
                p -> right  = q -> right;
                q -> right = p -> right;
                q -> left = p;
            }
        }
        if(!st.empty())
        {
            if(p -> val < p -> right -> val)
            {
                p = st.top();
                st.pop();
                p = p -> right;
            }
        
            else
            {
                q = p -> right;
                if(st.top() ->left == p)
                    st.top() -> left = q;
                else
                    st.top() -> right = q;
                p -> left = q -> left;
                p -> right  = q -> right;
                q -> left = p -> left;
                q -> right = p;
            }
        }
    }
    
}
*/