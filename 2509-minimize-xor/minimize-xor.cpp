class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);       //count no. of set bits
        int x=0;
        //cancel the 1s from msb to lsb
        for(int i=31 ; i>=0 and count ;i--){

            if(num1 & (1<<i)){
                count--;
                x+=(1<<i);
            }


        }
        //set 1s in lsb to msb 
        for(int i=0 ; i<32 and count ;i++){
            if((num1 &(1<<i))==0){
                count--;
                x+=(1<<i);

            }

        }
        return x;


        
    }
};