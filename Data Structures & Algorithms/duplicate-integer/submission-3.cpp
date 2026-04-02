#include <bits/stdc++.h>

class Solution {
public:

    bool hasDuplicate(vector<int>& nums) {
        map <int, int> myMap;

        for(auto i: nums){
            myMap[i]++;
            if(myMap[i] > 1){
                return true;
            }
        }

        return false;
    }
};
