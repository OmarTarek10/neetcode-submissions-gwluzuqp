class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<vector<int>> res;
        int sum = 0;
        b(0, nums, path, res, sum, target);
        return res;
    }

    void b(int idx, vector<int>& nums, vector<int> &path, vector<vector<int>> &res,int &curS ,int&target){

        if(target - curS == 0){
            res.push_back(path);
            return;
        }
        else if(curS > target){
            return;
        }

        for(int i =idx; i < nums.size() ; i++){
            path.push_back(nums[i]);
            curS += nums[i];
            b(i, nums, path, res, curS, target);
            curS -= nums[i];
            path.pop_back();
        }


    }
};
