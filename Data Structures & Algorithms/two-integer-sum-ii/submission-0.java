class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int ptr1 = 0;
        int ptr2 = numbers.length-1;
        int answer[]=new int [2];
        for(int i =0 ; i < numbers.length; i++){
            if(target == numbers[ptr1]+numbers[ptr2]){
                answer[0]=ptr1+1;
                answer[1]=ptr2+1;
                break;
            }
            else if(target > numbers[ptr1]+numbers[ptr2]){
                ptr1++;
            }
            else if(target < numbers[ptr1]+numbers[ptr2]){
                ptr2--;
            }    
        }

        
        return answer;

    }
}
