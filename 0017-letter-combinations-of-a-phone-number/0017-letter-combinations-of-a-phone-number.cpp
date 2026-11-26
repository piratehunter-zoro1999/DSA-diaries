class Solution {
public:
    
    void helper(vector<string> &tab, string &temp,vector<string> &ans,int idx,string digits){

         if(idx == digits.size()){
             ans.push_back(temp);
             return; 
         }

         int dup = digits[idx] - '0' -2;
          
          for(int i = 0;i<tab[dup].size();i++){
             temp+=tab[dup][i];
             helper(tab,temp,ans,idx + 1,digits);
             temp.pop_back();
          }
        
    }
    vector<string> letterCombinations(string digits) {
         if (digits == "") return {};
        vector<string> tab={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; // -2
        vector<string> ans;

       
         string temp="";
            helper(tab,temp,ans,0,digits);
        
           
        return ans;
    }
};