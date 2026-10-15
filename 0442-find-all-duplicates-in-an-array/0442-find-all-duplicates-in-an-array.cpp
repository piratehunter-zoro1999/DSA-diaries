class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n+1,0);
        vector<int> ans;

        for(int i : nums){
            if(check[i]==1){
                ans.push_back(i);
            }
            else{
                check[i]=1;
            }
        }

        return ans;
    }
};