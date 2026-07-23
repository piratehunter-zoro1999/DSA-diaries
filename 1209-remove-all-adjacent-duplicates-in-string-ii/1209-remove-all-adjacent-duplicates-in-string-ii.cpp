class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>> st;

        for(int i=0;i<n;i++){
          
           if(!st.empty() && st.top().first == s[i]){
            int NewCount = st.top().second+1;
            if(NewCount == k){
                st.pop();
            }else{
                st.pop();
                st.push({s[i],NewCount});
            }
           }else{
           st.push({s[i],1});
           }
        }
        if(st.empty()) return "";

        
        string ans="";
        while(!st.empty()){
            int x = st.top().second;

            for(int i =0 ;i<x;i++){
                ans+=st.top().first;
            }
           
           st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};