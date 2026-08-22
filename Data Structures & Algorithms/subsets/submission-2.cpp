class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        b(0, nums, path, res);
        return res;
    }

    void b(int idx, vector<int>& nums, vector<int> &path, vector<vector<int>> &res){

        if(idx == nums.size()){
            res.push_back(path);
            return;
        }


        // for(int i =0; i < nums.size() ; i++){
            path.push_back(nums[idx]);
            b(idx+1, nums, path, res);
            path.pop_back();
            b(idx+1, nums, path, res);
        // }


    }
};
