class DSU{
    vector<int> parent;
    vector<int> size;
    int n;
public:
    DSU(int n){
        this->n=n;
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int x){

        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int a ,int b){
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
    int count(){
        int x=0;
        for(int i =0 ;i<n;i++ ){
            if(find(i)==i) x++;
        }

        return x;
    }
};
class Solution {
public:
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU d(n);
        int count=0;
        for(int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1]==stones[j][1]){
                    d.Union(i,j);
                }
            }
        }
        return n-d.count();
    }
};