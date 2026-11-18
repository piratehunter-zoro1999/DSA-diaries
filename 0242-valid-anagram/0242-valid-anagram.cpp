class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.size();

        if(n != t.size()) return false;
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());
        
        
        for(int i=0;i<n;i++){
            if(t[i]!=s[i]) return false;
        }
       return true;
    }
};