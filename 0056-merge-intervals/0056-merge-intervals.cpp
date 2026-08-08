class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans = {intervals[0]};
        
        for(int i=1;i<n;i++){
           if(ans.back().back() >=intervals[i][0] && ans.back().back() < intervals[i][1]){
            auto temp = {ans.back().front(),intervals[i][1]};
            ans.pop_back();
            ans.push_back(temp);
           }else if(ans.back().back()< intervals[i].back()){
            ans.push_back(intervals[i]);
           }
        }
        return ans;
    }
};