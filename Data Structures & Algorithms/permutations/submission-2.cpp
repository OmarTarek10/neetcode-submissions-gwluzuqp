class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);

        backTrack(used, nums, path, res);
        return res;
    }

    void backTrack(vector<bool> &used, vector<int>& nums,vector<int> &path, vector<vector<int>> &res){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        else if(path.size() > nums.size()){
            return;
        }

        for(int i = 0; i< nums.size(); i ++){
            if(used[i]){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backTrack(used, nums, path, res);
            path.pop_back();
            used[i]= false;
        }
    }
};
