class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, candidates, path, res, target);
        return res;
    }

    void dfs(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& res, int target) {
        if(idx >= nums.size() || target < 0){
            return;
        }
        if(target == 0){
            res.push_back(path);
            return;
        }

        path.push_back(nums.at(idx));
        dfs(idx, nums, path, res, target-nums.at(idx));
        path.pop_back();
        dfs(idx+1, nums, path, res, target);
    }
};