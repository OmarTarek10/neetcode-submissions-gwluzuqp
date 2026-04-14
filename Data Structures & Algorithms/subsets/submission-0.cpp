class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0,path,res, nums);
        return res;
    }

    void dfs(int idx, vector<int> &path, vector<vector<int>> &res, vector<int>& nums){
        if(idx> nums.size()){
            return;
        }

        if(idx == nums.size()){
            res.push_back(path);
            return;
        }

        path.push_back(nums.at(idx));
        dfs(idx+1,path,res, nums);
        path.pop_back();
        dfs(idx+1,path,res, nums);
        
    }
};