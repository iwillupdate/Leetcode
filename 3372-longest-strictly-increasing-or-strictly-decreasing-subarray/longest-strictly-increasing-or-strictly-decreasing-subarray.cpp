class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxLength=0;
        int len=0;
        for(int i=0 ; i<n ;i++){
            len=1;
            for(int j=i+1 ; j<n ; j++){
                if(nums[j]>nums[j-1]){
                    len++;

                }
                else{
                    break;
                }
            }
            maxLength=max(maxLength,len);
        }
        for(int i=0 ; i<n ;i++){
            len=1;
            for(int j=i+1 ; j<n ; j++){
                if(nums[j]<nums[j-1]){
                    len++;

                }
                else{
                    break;
                }
            }
            maxLength=max(maxLength,len);
        }
        return maxLength;
        
    }
};