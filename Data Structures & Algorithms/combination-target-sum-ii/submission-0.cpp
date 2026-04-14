class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, candidates, target, res, path);
        return res;
    }

    void dfs(int start, vector<int>& nums, int target,
             vector<vector<int>>& res, vector<int>& path) {

        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {

            // 🔑 skip duplicates at same level
            if (i > start && nums[i] == nums[i - 1]) continue;

            if (nums[i] > target) break; // pruning

            path.push_back(nums[i]);

            // move forward (use each element once)
            dfs(i + 1, nums, target - nums[i], res, path);

            path.pop_back();
        }
    }
};