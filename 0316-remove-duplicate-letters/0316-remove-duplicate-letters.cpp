class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans="";
        vector<int>freq(26,0);
        vector<bool> check(26,0);
        for(int i=0;i<n;i++){
             freq[s[i]-97]++;
        }

        for(int i=0;i<n;i++){
           if(check[s[i]-97] == false){
               while(!ans.empty() &&freq[ans.back()-97] > 0   &&  ans.back() > s[i]){
                
                check[ans.back()-97]=false;
                ans.pop_back();
                
               }
               
               
                check[s[i]-97]=true;
                ans+=s[i];
               
           }
            freq[s[i]-97]--;
             

               
                
           
        }

        return ans;
    }
};