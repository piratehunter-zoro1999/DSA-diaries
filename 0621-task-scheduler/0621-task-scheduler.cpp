class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26,0);

        for(int i=0;i<tasks.size();i++){
            freq[tasks[i] - 65]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(int i =0;i<26;i++){
            if(freq[i]>0){
               pq.push({freq[i],i});
            }
             
        }
        int count=0;
        while(!pq.empty()){
            
            int size=pq.size();

            int executed=0;
            
            vector<pair<int,int>>v;
            for(int i=0;i<n+1 && !pq.empty();i++){
                
               if(pq.top().first-1>0){ 
                  
                  v.push_back({pq.top().first-1,pq.top().second});
               }

               pq.pop();

               executed++;
               count++;
              
            }

            for(auto p : v){
                pq.push(p);
            }  
            
            if(!pq.empty()){
                count+=n-executed+1;
            }

              

        }

        return count;
    }
};