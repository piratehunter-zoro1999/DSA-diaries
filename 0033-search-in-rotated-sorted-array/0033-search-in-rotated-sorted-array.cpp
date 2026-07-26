class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st =0;
        int end=nums.size()-1;

        while(st<=end){
            int mid= st+(end-st)/2;
            if(nums[mid] == target) return mid;
              
            if(nums[st]<=nums[mid]){// left part is sorted

              if(nums[st]<= target && target < nums[mid]){ //  target is on left with left-->sorted
                 end=mid-1;
              }else{  // target on right with left-->sorted
                 st=mid+1;
              }
            }else{ // right is sorted

              if(nums[mid] < target && target <=nums[end]){ // target is on right with right-->sorted
                   st=mid+1;
              }else{
                end=mid-1; // target on left with right-->sorted
              }
            }
        }

        return -1;
        
    }
};