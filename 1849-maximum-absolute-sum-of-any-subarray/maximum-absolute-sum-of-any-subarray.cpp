class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min_sum=0;
        int max_sum=0;
        int curr_sum=0;
        int max_abs_sum=0;

        for(int n:nums){
            curr_sum += n;
            max_abs_sum = max(max_abs_sum , max(abs(curr_sum - min_sum) , abs(curr_sum - max_sum)));
            min_sum = min(min_sum , curr_sum);
            max_sum = max(max_sum , curr_sum);
        
        }
        return max_abs_sum;

    }
};