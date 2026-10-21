class Solution {
public:

    int nextSum(int n){

        int sum=0;

        while(n>0){
            int temp=n%10;

            sum+=temp*temp;

            n/=10;
        }

        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = nextSum(n);

        while(fast!=1 && fast!=slow){
            slow=nextSum(slow);
            fast=nextSum(nextSum(fast));
        }

        return fast==1? true: false;
    }
};