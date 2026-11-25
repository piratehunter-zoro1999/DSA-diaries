class Solution {
public:

         vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
           int sec = target - nums[i];

           if(mp.find(sec) != mp.end()){
             return {mp[sec],i};
           }

           mp[nums[i]]=i;
        }

        return{};
    }
    
};