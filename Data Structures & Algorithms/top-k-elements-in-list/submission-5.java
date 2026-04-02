class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a,b) -> Integer.compare(b.getValue(), a.getValue()));
        Map<Integer, Integer> freq = new HashMap<>();

        for(int i: nums){
            freq.put(i,freq.getOrDefault(i,0)+1);
        }

        for(Map.Entry<Integer, Integer> entry: freq.entrySet()){
            pq.add(entry);
        }

        int [] res = new int [k];
        int ctr=0;
        for(int i =0; i < k ;i++){
            res[i]=pq.poll().getKey();
        }

        return res;
    }
}
