class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long num=x , rem , q=0;
        long b=num;

        while(num>0){
            rem=num%10;
            num=num/10;
            q=q*10+rem;
        }
        return q==b;
        
    }
};