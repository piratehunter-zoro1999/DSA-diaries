class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n);
        dp[0]=1;
        

        for(int i =1;i<n;i++){
            int candidate=1;
           for(int j=0;j<i;j++){
              if(nums[j]<nums[i]){
                 candidate=max(candidate,dp[j]+1);
              }
           }
           dp[i]=candidate;
        }

        return *max_element(dp.begin(),dp.end());
    }
};