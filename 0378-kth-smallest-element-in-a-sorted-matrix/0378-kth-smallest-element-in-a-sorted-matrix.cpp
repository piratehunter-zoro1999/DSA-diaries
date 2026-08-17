class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n = matrix.size();

        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],i,0});
        }

        for(int i=1;i<k;i++){
            vector<int> v=pq.top();
            pq.pop();
            if(v[2]+1<n){
               v[2]++;
               v[0]=matrix[v[1]][v[2]];
               pq.push(v);

            }
        }

        vector<int> ans=pq.top();

        return ans[0];



    }
};