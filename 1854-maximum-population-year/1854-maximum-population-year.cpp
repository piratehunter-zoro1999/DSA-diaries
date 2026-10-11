class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(101,0);

        for(int i=0;i<logs.size();i++){
            int birth = logs[i][0];
            int death = logs[i][1];

            years[birth-1950]+=1;
            years[death-1950]-=1;
        }
           int count=0;
           int ans=0;
           int pre=0;

        for(int i =0;i<100;i++){
           count+=years[i];
           
           if(count>pre){
             pre = count;
             ans=i;
           }

        }

        return ans+1950;
    }
};