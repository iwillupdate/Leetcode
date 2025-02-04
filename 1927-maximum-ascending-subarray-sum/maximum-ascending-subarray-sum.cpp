class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int count=nums[0];
        int ans=0;
        int n=nums.size();
        for(int i=1 ; i<n;i++){
            if(nums[i]>nums[i-1]){
                count = count+nums[i];
            }
            else{
                ans = max(ans,count);
                count = nums[i];
            }

        }
        return max(count,ans);
    }
};