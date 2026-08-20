class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;

        for(int i =0; i < piles.size(); i++){
            if(piles[i] > r){
                r = piles[i];
            }
        }

        int rate = r;

        while(l <= r){
            int k = l+ (r-l)/2;
            int totalTime=0;
            for(int &pile: piles){
                totalTime += ceil((double)pile/k);
            }

            if(totalTime<=h){
                rate = k;
                r = k-1;
            }
            else{
                l = k+1;
            }
        }

        return rate;

    }
};
