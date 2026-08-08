class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        
        unordered_map<string,int> freq;

        for(auto& it : words){
            freq[it]++;
        }

        vector<pair<string,int>> ele;

        for(auto &it : freq){
            ele.push_back(it);
        }

        sort(ele.begin(),ele.end(),
        [](auto &a ,auto &b){
            if(a.second == b.second){
                return a.first<b.first;
            }else{
                return a.second>b.second;
            }
        }
        );
        vector<string> ans;
        for(int i =0 ;i<k;i++){
            ans.push_back(ele[i].first);
        }

        return ans;
    }
};