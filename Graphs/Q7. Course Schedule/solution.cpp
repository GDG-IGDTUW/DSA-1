class Solution {
public:
    bool hasCycle(int src,vector<vector<int>>& adj,vector<bool>&vis,vector<bool>&recPath) {
        vis[src]=true;
        recPath[src]=true;

        for(int ngh:adj[src]){
            if(!vis[ngh]){
                if(hasCycle(ngh,adj,vis,recPath)){
                    return true;
                }

            }
            else if(recPath[ngh]){
                return true;
            }

        }
        recPath[src]=false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &course:prerequisites){
            adj[course[1]].push_back(course[0]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(hasCycle(i,adj,vis,recPath)){
                    return false;
                }
            }
        }
        return true;
        
    }
};
