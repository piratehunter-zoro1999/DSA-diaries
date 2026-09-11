class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const long long LIMIT = INT_MAX;
        vector<long long> dp(target + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= target; i++) {
            for(int num : nums) {
                if(num <= i) {
                    dp[i] += dp[i - num];

                    if(dp[i] > LIMIT)
                        dp[i] = LIMIT;
                }
            }
        }

        return (int)dp[target];
    }
};