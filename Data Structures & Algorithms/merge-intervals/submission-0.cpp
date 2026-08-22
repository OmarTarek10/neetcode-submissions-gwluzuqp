class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);

        for(vector<int> &interval: intervals){
            int start = interval[0];
            int end = interval[1];
            int lastE = res.back()[1];

            if(lastE >= start){
                res.back()[1] = max(lastE, end);
            }
            else{
                res.push_back(interval);
            }
        }  
        return res;
    }
};
