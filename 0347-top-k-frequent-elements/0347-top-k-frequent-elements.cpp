class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;

        for(int i : nums){
            freq[i]++;
        }

        vector<pair<int,int>> elements;

        for(auto &it : freq){
            elements.push_back(it);
        }

        sort(elements.begin(),elements.end(),
        [](auto &a,auto &b){
            if(a.second == b.second){
                return a.first<b.second;
            }
            return a.second>b.second;
        }
        );

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(elements[i].first);
        }
        return ans;
    }
};