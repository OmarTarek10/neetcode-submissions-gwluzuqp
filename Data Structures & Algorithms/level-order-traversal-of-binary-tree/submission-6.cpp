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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode*> q;

        q.push(root);

        int level = 0;

        while(!q.empty()){
            vector<int> s;
            int size = q.size();
            for(int i =0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current == nullptr){
                    continue;
                }
                if(current){
                    s.push_back(current->val);
                    q.push(current->left);
                    q.push(current->right);
                }
            }
            if(!q.empty()){
                level++;
                res.push_back(s);
            }

        }

        return res;
    }


};
