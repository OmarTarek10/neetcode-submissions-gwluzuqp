class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        int costSum = 0;

        for(int i = 0 ; i < gas.size();i++){
            gasSum+=gas[i];
            costSum+=cost[i];
        }
        int res =0;

        if(gasSum < costSum){
            return -1;
        }
        else{
            int currentGas = 0;
            for(int i =0; i < gas.size();i++){
                currentGas += gas[i] - cost[i];
                if(currentGas < 0){
                    currentGas = 0;
                    res = i+1;
                }
            }
        }
        return res;

    }
};
