class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int maxVal = *max_element(nums.begin(),nums.end());

        vector<int> points(maxVal+1,0),dp(maxVal+1,0);

        for(int num :nums){
            points[num]+=num;
        }

        

        dp[0]=points[0];
        dp[1]=max(points[0],points[1]);

        for(int i=2;i<=maxVal;i++){
            dp[i]=max(dp[i-1],dp[i-2]+points[i]);
        }

        return dp[maxVal];

    }
};