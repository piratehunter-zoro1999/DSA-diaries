class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> st;
        for(string c : wordDict){
           st.insert(c);
        }

        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        
        string x="";
        for(int i=1;i<=n;i++){
          for(int j=0;j<i;j++){
             if(dp[j] && st.find(s.substr(j,i-j))!=st.end()){
                dp[i] = true;
                break;
             }
          }
        }

        return dp[n];
    }
};