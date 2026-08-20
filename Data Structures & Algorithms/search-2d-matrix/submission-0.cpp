class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(); int cols = matrix[0].size();
        int num = rows*cols-1;

        int l = 0;
        int r = num;

        while(l<=r){
            int m = l+(r-l)/2;
            
            int rr = m/(matrix[0].size());
            int cc = m%(matrix[0].size());


            if(matrix[rr][cc] < target){
                l = m+1;
            }
            else if(matrix[rr][cc]> target){
                r = m-1;
            }
            else{
                return true;
            }
        }
        return false;

        
    }
};
