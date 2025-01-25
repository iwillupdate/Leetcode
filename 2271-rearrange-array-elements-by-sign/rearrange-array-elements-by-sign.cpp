class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int pos=0 , neg=1;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos += 2;
            }
            else{
                ans[neg]=nums[i];
                neg += 2;
            }
        }
        return ans;


        
    }
};


// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {

//         int n=nums.size();
//         vector<int> pos , neg;
//         for(int i=0 ;i<n;i++){
//             if(nums[i]>0)       pos.push_back(nums[i]);
//             else neg.push_back(nums[i]);
//         }
//         for(int i=0 ; i<n/2 ; i++){
//             nums[2*i]=pos[i];
//             nums[2*i + 1]=neg[i];
//         }
//         return nums;
        
//     }
// };