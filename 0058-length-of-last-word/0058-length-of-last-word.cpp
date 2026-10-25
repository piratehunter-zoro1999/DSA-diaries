class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        
        int temp;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                 temp=i;
                 break;
            }
        }
       int  count=0;
         for(int i=temp;i<s.size();i++){
            if(s[i]!=' ') count++;
            else break;
        }

        return count;
    }
};