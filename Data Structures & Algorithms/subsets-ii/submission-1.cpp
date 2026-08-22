class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> res;
        b(0, nums, path, res);
        return res;
    }

    void b(int idx, vector<int>& nums, vector<int> &path, vector<vector<int>> &res){

        res.push_back(path);


        for(int i =idx; i < nums.size() ; i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            b(i+1, nums, path, res);
            path.pop_back();
        }


    }
};
