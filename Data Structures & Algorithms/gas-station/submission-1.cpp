class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum =0;
        int costSum=0;

        for(int i=0;i<gas.size();i++){
            gasSum += gas.at(i);
            costSum += cost.at(i);
        }

        if(gasSum < costSum){
            return -1;
        }

        int total=0;
        int result=0;
        for(int i=0;i<gas.size();i++){
            total+= gas.at(i)-cost.at(i);
            if(total<0){
                total=0;
                result=i+1;
            }
        }

        return result;
    }
};
