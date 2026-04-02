class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> targets;
        map<int, int> mp;
        signed long long diff;

        for (unsigned int i =0; i< nums.size(); i++){
            diff = target-nums[i];
            mp[diff] = i;
        }

        for (unsigned int i =0; i< nums.size(); i++){
            if (mp.find(nums[i]) != mp.end()) {
                if(i!=mp[nums[i]]){
                    targets.push_back(i);
                    targets.push_back(mp[nums[i]]);
                    break;
                }
            }
        }

        return targets;
    }
};
