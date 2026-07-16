class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(auto p : pre ){
            int u = p[0];
            int v = p[1];

            adj[v].push_back(u);
            indegree[u]++;
        } 
        queue<int> q;

        for(int i = 0 ;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
       int processed = 0;
        while(!q.empty()){
     
             int c = q.front();
             q.pop();
             processed++;

             for(int v : adj[c]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
             }

             

        }
        return processed==n;

    }
};