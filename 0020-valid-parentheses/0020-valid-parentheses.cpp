class Solution {
public:
    
    char check(char c){
        if(c == ']') return '[';
        if(c== '}') return '{';
        else return '(';
    }
    bool isValid(string s) {

        int n = s.size();
        stack<char> st;

        for(int i =0 ;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
               st.push(s[i]);
            }else{
                if(!st.empty() && check(s[i])==st.top()){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        return st.empty();
        
    }
};