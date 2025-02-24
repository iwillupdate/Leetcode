class Solution {
public:
    bool canJump(vector<int>& nums) {

        int reach=0;
        for(int i=0 ; i<nums.size();i++){
            if(i>reach)     return 0;

            reach=max(reach , nums[i]+i);


        }
        return 1;
        
        
    }
};