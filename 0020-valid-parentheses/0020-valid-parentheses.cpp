class Solution {
public:
    char check(char c){
        if(c == ')') return '('; 
        if(c == ']') return '['; 
         return '{'; 
    }
    
    bool isValid(string s) {
        stack<char> st;

        int n =s.size();

        for(int i = 0;i<n;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(!st.empty() && st.top() == check(s[i])){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        return st.empty()? true: false;

        
    }
};