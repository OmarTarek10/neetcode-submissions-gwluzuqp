class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> s= new HashSet<>();
        int longest = 0;
        for(int n: nums){
            s.add(n);
        }

        for(int i =0; i < nums.length; i++){
            if(!s.contains(nums[i]-1)){
                int number = nums[i];
                int ctr=1;
                while(s.contains(number+1)){
                    number++;
                    ctr++;
                }
                if(ctr > longest){
                    longest = ctr;
                }
            }
            continue;
        }
        return longest;
    }
}
