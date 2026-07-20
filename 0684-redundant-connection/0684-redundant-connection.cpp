class Solution {
public:
    vector<int> parent;
    vector<int> size;
 

    int find(int x){
        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int a, int b){
        int p1 = find(a);
        int p2 = find(b);

        if(p1 == p2) return;

        if(size[p1]>=size[p2]){
            parent[p2]=p1;
            size[p1]+=size[p2];

        }else{
            parent[p1]=p2;
            size[p2]+=size[p1];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

         parent.resize(n+1);
       size.assign(n+1,1);

       for( int i=0;i<=n;i++){
        parent[i]=i;
       }
        
        

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            
            if(find(u)==find(v)){
                return e;
            }

            Union(u,v);
        }

       return {};
    }
};