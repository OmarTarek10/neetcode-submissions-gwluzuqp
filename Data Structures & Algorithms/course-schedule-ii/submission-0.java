class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int []arr = new int[numCourses];
        List<List<Integer>> adj=new ArrayList<>();

        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }

        for(int []pre:prerequisites){
            arr[pre[1]]++;
            adj.get(pre[0]).add(pre[1]);
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
            s.push(current);
            // ansArr[counter]=current;
            counter++;
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

        if(counter == numCourses){
            for(int i=0;i<numCourses;i++){
                ansArr[i] = s.pop();
            }
            return ansArr;
        }
        return new int[0];

    }
}