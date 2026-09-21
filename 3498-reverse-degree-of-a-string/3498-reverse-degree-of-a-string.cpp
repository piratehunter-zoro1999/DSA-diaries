class Solution {
public:
    int reverseDegree(string s) {

        int n = s.size();
        int sum=0;
        for(int i =0 ;i<n;i++){

            sum+=(26-(s[i]-97))*(i+1);

        }
        return sum;
        
    }
};