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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if(!root){
            return {};
        }
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int last;
            for(int i =0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                last = current->val;
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
            view.push_back(last);
        }

        return view;
    }
};
