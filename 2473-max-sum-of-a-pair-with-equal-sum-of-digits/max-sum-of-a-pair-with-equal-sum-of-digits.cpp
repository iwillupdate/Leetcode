class Solution {
    int getDigitSum(int val){
        int sum=0;
        while(val){
            sum = sum + val%10;
            val = val/10;
        }
        return sum;

    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>sum_maxvalue;
        int max_sum=-1;
        for(int num:nums){
            int digit_sum = getDigitSum(num);
            if(sum_maxvalue.count(digit_sum)){
                max_sum = max(max_sum , num + sum_maxvalue[digit_sum]);
               
            }
             sum_maxvalue[digit_sum] = max(sum_maxvalue[digit_sum], num);
        }
        return max_sum;

    }
};