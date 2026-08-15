class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n= nums.size();

        for(int i =0 ;i<n ;i++){
             s.insert(nums[i]);
        }
        int maxlen=0;
        for(int num : s){
            if(s.find(num-1)==s.end()){
                int len=1;
                int curr=num;
                while(s.find(curr+1)!=s.end()){
                    len++;
                    curr++;
                }

                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};