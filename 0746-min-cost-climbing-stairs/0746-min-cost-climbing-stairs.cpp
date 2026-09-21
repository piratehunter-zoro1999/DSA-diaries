class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev1=0;
        int prev2=0;
    

        for(int i=2;i<n+1;i++){
           int result=min(prev2+cost[i-1],prev1+cost[i-2]);
           prev1=prev2;
           prev2=result;
        }

        return prev2;
    }
};