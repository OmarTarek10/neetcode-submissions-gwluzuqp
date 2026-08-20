class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stack;

        int fleet = 0;
        for (auto& p : pair) {
            double currentTime = ((double)(target - p.first) / p.second);
        
            while(stack.empty() || currentTime > stack.back()){
                fleet++;
                stack.push_back(currentTime);
            }
            // if (stack.size() >= 2 &&
            //     stack.back() <= stack[stack.size() - 2])
            // {
            //     stack.pop_back();
            // }
        }
        return stack.size();
    }
};
