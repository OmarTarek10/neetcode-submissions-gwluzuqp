class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        
        vector<vector<int>> result;

        backTrack(0,nums, path, result);

        return result;
    }

    void backTrack(int idx, vector<int>& nums,vector<int> &path, vector<vector<int>> &result){

        if(idx == nums.size()){
            result.push_back(path);
            return;
        }

        path.push_back(nums[idx]);
        backTrack(idx+1,nums,path,result);
        path.pop_back();
        backTrack(idx+1,nums,path,result);

    }
};
