class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())        return 0;
        sort(nums.begin() , nums.end());
        int count=1 , maxi=1;
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i] + 1 == nums[i+1]){
                count++;
                maxi=max(maxi , count);
            }
            else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                count=1;
            }
        }
        return maxi;
        
        
    }
};