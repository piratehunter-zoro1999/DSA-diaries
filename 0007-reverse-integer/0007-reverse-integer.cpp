class Solution {
public:
    int reverse(int x) {

        long long num=0;

        bool flag=0;

        long long y=x;

        if(y<0) {
            y*=-1;
            flag=1;
        }    
        
        while(y>0){

           num= num*10 + y % 10;

           y=y/10;
        }

        if(num>= 1U << 31) return 0;

        return flag?num*-1:num;
    }
};