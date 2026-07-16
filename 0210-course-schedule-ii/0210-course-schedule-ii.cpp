class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(auto p : pre){
            int v = p[0];
            int u = p[1];

           adj[u].push_back(v);
           indegree[v]++;
        }

        queue<int> q;

        for(int i = 0 ;i < n ;i++ ){
           if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        int processed=0;
        while(!q.empty()){
              int u = q.front();
              q.pop();
              processed++;
              ans.push_back(u);

              for( int v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
              }
        }
       if(processed == n) return ans;
       else return {};
    }
};