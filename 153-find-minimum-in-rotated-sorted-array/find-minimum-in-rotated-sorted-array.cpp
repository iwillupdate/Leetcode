class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0 ; i<nums.size() ; i++){
            mini=min(mini , nums[i]);
        }
        return mini;
        
    }
};