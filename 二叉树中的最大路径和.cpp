#include<iostream>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int main()
{
    return 0;
}
class Solution {
public:

    int MAX = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return MAX;
    }
        
    int dfs(TreeNode* root)
    {
        if(root == NULL) return 0;

        int sum = root -> val;
        int left = dfs(root -> left);
        int right = dfs(root -> right);

        if(left > 0)    sum += left;
        if(right > 0)   sum += right;

        MAX = max(MAX,sum);

        return max(0,max(right,left)) + root -> val;
    }

};


