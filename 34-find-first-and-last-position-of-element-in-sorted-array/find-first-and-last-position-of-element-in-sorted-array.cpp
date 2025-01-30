class Solution {

    private:
    int firstOcc(vector<int>&nums,int target){
        
        int low=0 , high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                //eliminate rhs
                high=mid-1;
            }
            else if(nums[mid]<target){
                //eliminate lhs
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return first;

    }



    int lastOcc(vector<int>&nums,int target){
        
        int low=0 , high=nums.size()-1;
        int last=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last=mid;
                //eliminate lhs
                low=mid+1;
            }
            else if(nums[mid]<target){
                //eliminate lhs
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return last;

    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums,target);
        if (first==-1)      return{-1,-1};
        int last=lastOcc(nums,target);
        return{first,last};
        
    }
};