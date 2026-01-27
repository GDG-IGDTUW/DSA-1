class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<numCourses; i++){
            adj.add(new ArrayList<>()); //creating the adjacency list
        }
        int indegree[] = new int[numCourses];
        
        for(int pre[] : prerequisites){
            int to = pre[0];
            int from = pre[1];
            indegree[to]++;
            adj.get(from).add(to); //populating the adjacency list
        }

        Queue<Integer> q = new LinkedList<>();
        for(int course=0; course<numCourses; course++){
            if(indegree[course]==0){
                q.offer(course); //finding the starting node.
            }
        }

        int ans[] = new int[numCourses];
        int ind=0;
        int completed = 0;
        while(!q.isEmpty()){ //Kahn's algo
            int currCourse = q.poll();
            completed++;
            ans[ind++] = currCourse;
            for(int neighbour : adj.get(currCourse)){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.offer(neighbour);
                }
            }
        }
        if(completed<numCourses)
            return new int[]{};
        return ans;
    }
}
