class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int l=1;
        int r=nums.size()-1;

        while(l<r){
            int mid=l+(r-l)/2;
            int cnt=0;

            for(int num:nums){
                if(num<=mid){
                    cnt++;
                }
            }
            if(cnt>mid){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;  
    }
};