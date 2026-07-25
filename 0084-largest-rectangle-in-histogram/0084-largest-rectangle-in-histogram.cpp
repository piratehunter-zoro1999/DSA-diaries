class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n= h.size();
        vector<int> left(n,0);
        stack<int>s1;

        for(int i = n-1 ;i>=0 ;i--){

            while(!s1.empty() && h[s1.top()]>= h[i]){
                s1.pop();
            }

           s1.empty()?left[i]=n:left[i]=s1.top();
           s1.push(i);
        }

        vector<int> right(n,0);
        stack<int> s2;

        for(int i =0 ;i<n ;i++){
            while(!s2.empty() && h[s2.top()]>= h[i]){
                s2.pop();
            }
            s2.empty()?right[i]=-1:right[i]=s2.top();
            s2.push(i);
        }

         int judge=0;
        for(int i=0 ;i<n;i++){
            judge=max(judge,h[i]*(left[i]-right[i]-1));
        }
      
      return  judge;
    }
};