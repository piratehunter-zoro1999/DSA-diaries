class Solution {
public:
     
    
    int findDuplicate(vector<int>& nums) {
     int st= 1, end= nums.size()-1;

     while(st<end){

        int mid = st + (end-st)/2;
        int count=0;
        for(int i : nums){
           if(i <= mid) count++;
        }

        if(count>mid) end=mid;
        else st=mid+1;
     }
       
    return st;
    }
};