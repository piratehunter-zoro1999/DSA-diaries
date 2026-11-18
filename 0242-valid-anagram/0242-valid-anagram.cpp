class Solution {
public:
    bool isAnagram(string s, string t) {
 
        int n= s.size();
        if(t.size() != n) return false;

        unordered_map<int,int> mp;

        for(int i=0 ;i<n;i++){
            mp[s[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mp[t[i]] == 0) return false;
            mp[t[i]]--;
        }

        return true;
    }
};