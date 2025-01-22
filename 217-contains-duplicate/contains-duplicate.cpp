class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //BRUTE FORCE
        // int n=nums.size();
        
        // for(int i=0 ; i<n ; i++){
        //     int ele = nums[i];
        //     for(int j=i+1 ; j<n ;  j++){
        //         if(ele ==nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        //USING SORT FUNCTION - O(nlogn)
        // sort(nums.begin() , nums.end());
        // for(int i=0 ; i<nums.size()-1 ; i++){
        //     if (nums[i]==nums[i+1]){
        //         return true;
        //     }
        // }
        // return false;

        //Maps
        unordered_map<int,int> mymap;
        for(auto a:nums ){
            mymap[a]++;
        }
        for(auto a : mymap){
            if(a.second > 1)        return true;
        }
        return 0;

        
    }
};