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
    TreeNode* lowest;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lowest = q;
        dfs(root,p->val,q->val);
        return lowest;

    }

    void dfs(TreeNode* root, int a, int b){
        if(root==nullptr){
            return;
        }
        if(root -> val > a && root->val > b){
            dfs(root->left,a,b);
        }
        else if(root -> val < a && root->val < b){
            dfs(root->right,a,b);
        }
        else{
            lowest = root;
            return;
        }
       
    }
};
