class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
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
            if(i>idx && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            curS += nums[i];
            b(i+1, nums, path, res, curS, target);
            curS -= nums[i];
            path.pop_back();
        }


    }

};