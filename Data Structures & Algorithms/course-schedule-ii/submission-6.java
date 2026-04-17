class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int []arr = new int[numCourses];
        List<List<Integer>> adj=new ArrayList<>();

        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }

        for(int []pre:prerequisites){
            arr[pre[0]]++;
            adj.get(pre[1]).add(pre[0]);
        }

        Deque<Integer> q = new ArrayDeque<>();
        for( int i =0;i<numCourses;i++){
            if(arr[i] == 0){
                q.add(i);
            }
        }

        int counter=0;
        Deque<Integer> s = new ArrayDeque<>();
        int ansArr[]=new int[numCourses];
        while(!q.isEmpty()){
            int current = q.poll();
            ansArr[counter++] = current;
            // ansArr[counter]=current;
            if(counter>numCourses){
                return new int[0];
            }
            for(int n: adj.get(current)){
                arr[n]--;
                if(arr[n]==0){
                    q.add(n);
                }
            }
        }
        if (counter != numCourses) return new int[0];
        return ansArr;


    }
}