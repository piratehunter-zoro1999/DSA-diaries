class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        int n = recipes.size();
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;

        for(int i=0;i<n;i++){
             int size=ingredients[i].size();
             for(int j=0;j<size;j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
             }
        }

        queue<string> q;

        for(auto &s : supplies){

           q.push(s);
        }
        vector<string> ans;
        
        while(!q.empty()){

            string in = q.front();
            q.pop();

           if(adj.find(in)==adj.end()) continue;

           for( auto &r : adj[in]){
              indegree[r]--;
              if(indegree[r]==0){
                 q.push(r);
                 ans.push_back(r);
              }
           }
         
        }
        return ans;
    }
};