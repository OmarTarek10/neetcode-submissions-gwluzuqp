class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mon;
        vector<int> res(temperatures.size(),0);

        for(int i =0; i < temperatures.size(); i ++){
            int current = temperatures[i];

            while(!mon.empty() && temperatures[mon.top()] < current ){
                int idx = mon.top();
                mon.pop();
                res[idx] = i-idx;
            }

            mon.push(i);
        }

        return res;
    }
};
