class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        
        vector<vector<int>> adj(numCourses);
        
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }        
        
        vector<int> topo;
        
        
        while(q.size()!=0){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(topo.size()==numCourses){
            return true;
        }
        
        return false;
    }
};