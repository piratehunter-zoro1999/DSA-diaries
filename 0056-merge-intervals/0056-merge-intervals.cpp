class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans = {intervals[0]};

        int n = intervals.size();

        for (int i = 1; i < n; i++) {
            if (intervals[i][1] > ans.back()[1]) {
                if (intervals[i][0] <= ans.back()[1]) {
                    ans.back()[1] = intervals[i][1];
                } else {
                    ans.push_back(intervals[i]);
                }
            }
        }

        return ans;
    }
};