class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int [] arr = new int[numCourses];
        List<List<Integer>> adj = new ArrayList<>();

        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }

        for(int i[]: prerequisites){
            arr[i[1]]++;
            adj.get(i[0]).add(i[1]);
        }

        Deque<Integer> q = new ArrayDeque<>();
        for(int i=0;i<numCourses;i++){
            if(arr[i]==0){
                q.add(i);
            }
        }

int count=0;
        while(!q.isEmpty()){
            int curr = q.poll();
            count++;
            for(int nei:adj.get(curr)){
                arr[nei]--;
                if(arr[nei]==0){
                    q.add(nei);
                }
            }
        }

        return count==numCourses;
        
    }
}
