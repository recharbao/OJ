#include<iostream>
#include<list>
using namespace std;


  

int main()
{
    return 0;
}




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        list<TreeNode*> L;
        pre_dfs(TreeNode* root,L);
        root = L;   
        chang(root,L);
    }
    pre_dfs(TreeNode* root,list<TreeNode*> L)
    {
        if(root != NULL)
        {
            L.push_back(root);
            pre_dfs(root -> left);
            pre_dfs(root -> right);
        }
    }
    chang(TreeNode* root,list<TreeNode*> L)
    {
        root -> right = L -> next;
        root -> left = NULL;
        L = L -> next;
        chang(L,L);
    }
};