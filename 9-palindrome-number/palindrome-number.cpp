class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long temp=x;
        long rev_num=0;
        while(x>0){
            if(rev_num>INT_MAX || rev_num<INT_MIN){
                return false;
            }

            long ld=x%10;
            rev_num=rev_num*10+ld;
            x=x/10;   
        }
        // if(rev_num==temp)   return true;
        // else                return false;
        return rev_num==temp;
        
    }
};