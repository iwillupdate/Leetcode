#include <cmath>
class Solution {

    private:
    int findMax(vector<int>&nums){
        int maxi=INT_MIN;
        int n=nums.size();

        for(int i=0 ; i<n ;i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    //total hrs
    int totalHours(vector<int>&nums,int hr){
        int totalH=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totalH += ceil((double)nums[i]/(double) hr);
        }
        return totalH;
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1 , high=findMax(piles);
        while(l<high){
            int mid=l+(high-l)/2;
            int totalH=totalHours(piles,mid);
            if(totalH<=h){
                high=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};