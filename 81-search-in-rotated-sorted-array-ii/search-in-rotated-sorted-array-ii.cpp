class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n=nums.size();
        // for(int i=0 ; i<n ; i++){
        //     if(nums[i]==target){
        //         return true;
        //     }
        // }
        // return false;
        
        int l=0 , h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[l]==nums[mid] and nums[mid]==nums[h]){
                l=l+1;
                h=h-1;
                continue;

            }
            //left part is sorted
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target and target<=nums[mid]){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }

            //right half
            else{
            if(nums[mid]<=target and target<=nums[h] ){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            }
        }
        return false;


        
    }
};