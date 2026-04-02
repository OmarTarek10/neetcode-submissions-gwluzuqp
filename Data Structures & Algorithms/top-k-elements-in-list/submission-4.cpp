class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        vector<vector<int>> frequencyVector(nums.size()+1);
        vector<int> results;

        for(auto num: nums){
            myMap[num] += 1;
        }

        for(auto myPair:myMap){
            frequencyVector[myPair.second].push_back(myPair.first);
        }
 
        for(int i = frequencyVector.size()-1; i> 0; i--){
            for(int j: frequencyVector[i]){
                results.push_back(j);
                if(results.size() == k){
                    return results;
                }
            }
        }
        return results;
    }
};
