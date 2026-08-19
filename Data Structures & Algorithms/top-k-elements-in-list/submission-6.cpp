class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        priority_queue<vector<int>> pq;

        for(auto &[key,value]: mp){
            pq.push({value,key});
        }

        vector<int> res;
        for(int i =0; i < k; i ++){
            res.push_back(pq.top()[1]);
            pq.pop();
        }

        return res;

    }
};
