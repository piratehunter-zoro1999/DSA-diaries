class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0;
        double sum=0;
        int j=0;

        while(i<k){
           sum+=nums[i];
           i++;
        }

        double avg=sum/k;

        while(i<n){
            sum=sum+nums[i]-nums[j];
            j++;
            i++;

            avg=max(avg,sum/k);
        }

        return avg;

    }
};