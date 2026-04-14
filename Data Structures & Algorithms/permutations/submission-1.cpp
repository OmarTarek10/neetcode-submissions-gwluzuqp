class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> bo(nums.size(), false);
        dfs(nums,bo,res,path);
        return res;
    }

    void dfs(vector<int>& nums,vector<bool> &bo, vector<vector<int>> &res, vector<int> &path){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i=0; i < nums.size();i++){
            if(!bo[i]){
                bo[i]=true;
                path.push_back(nums[i]);
                dfs(nums,bo,res,path);
                path.pop_back();
                bo[i]=false;
            }
        }

    }
};