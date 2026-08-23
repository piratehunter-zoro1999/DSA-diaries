class Solution {
public:
    int helper(vector<int> &nums,int l ,int r){
        
        vector<int>dp(nums.size());
        
        dp[l]=nums[l];
        if(l+1<r)
        dp[l+1]=max(nums[l],nums[l+1]);

        for(int i=l+2;i<r;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }

        return dp[r-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
       

        int ans = max(helper(nums,0,n-1),
                       helper(nums,1,n)
                       );

        return ans;               


        
    }
};