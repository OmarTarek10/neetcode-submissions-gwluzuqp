class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<vector<int>> res;
        int sum=0;
        backTrack(0,nums,path, res,sum,target);
        return res;
        
    }

    void backTrack(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>> &res, int &sum,int &target){
        if(sum == target){
            res.push_back(path);
            return;
        }
        else if(sum > target){
            return;
        }

        for(int i = idx; i < nums.size(); i ++){
            path.push_back(nums[i]);
            sum += nums[i];
            backTrack(i, nums, path, res, sum, target);
            sum-=nums[i];
            path.pop_back();
        }
    }
};
