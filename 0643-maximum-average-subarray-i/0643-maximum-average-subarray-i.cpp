class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0;
        int sum=0;
        int j=0;

        while(i<k){
           sum+=nums[i];
           i++;
        }

       int maxSum=sum;
        while(i<n){
            sum=sum+nums[i]-nums[j];
            j++;
            i++;
            maxSum=max(sum,maxSum);
        }

        return (double) maxSum/k;

    }
};