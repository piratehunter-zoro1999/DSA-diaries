class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int container=0;

        vector<int> change(1001,0);
        
        for(int i = 0 ; i<n ; i++){


            change[trips[i][1]]+=trips[i][0];
            change[trips[i][2]]-=trips[i][0];  

        }
      
        for(int i: change){
            container+=i;
            if(container>capacity) return false;
        }
        return true;
    }
};