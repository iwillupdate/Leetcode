class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n=nums.size();
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) a++;
            else a=0;

            if(b<a) b=a;
        }
        return b;

        

    }
};