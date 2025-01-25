class Solution {
public:
    vector<int> countBits(int n) {
        //mem[i]=no. of 1s from 0 to number i
        vector<int> mem(n+1);
        mem[0]=0;
        for(int i=1 ; i<=n ;i++){
            mem[i]=mem[i/2]+i%2;
        }
        return mem;
    }
};