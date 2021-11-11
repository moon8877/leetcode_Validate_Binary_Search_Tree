/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,LLONG_MIN, LLONG_MAX);
    }
    bool dfs(TreeNode* root,long min,long max){
        if(!root){return true;}

        if(root->left){
            if(root->left->val >= root->val || root->left->val<=min){return false;}
        }
        if(root->right){
            if(root->right->val <= root->val || root->right->val>=max){return false;}
        }
        
        return dfs(root->left,min,root->val) and dfs(root->right,root->val,max);
    }
};
