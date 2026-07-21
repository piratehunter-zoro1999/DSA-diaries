class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x){
        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
    }

    void Union (int a , int b){

        int p1= find(a);
        int p2= find(b);
        
        if(p1 == p2){
            return;
        }

        if(size[p1]>=size[p2]){
           parent[p2]=p1;
           size[p1]+=size[p2];
        }else{
            parent[p1]=p2;
            size[p2]+=size[p1];
        }
    }
 
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        size.assign(n,1);
        for(int i = 0 ;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    Union(i,j);
                }
            }
        }
    int ans=0;
        for(int i=0;i<n;i++){
          if(parent[i]==i) ans++;
        }

        return ans;
    }
};