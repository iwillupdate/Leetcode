//optimised
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int j=i+1 , k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                if(sum>0) k--;
                if(sum==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
        
    }
};



//better
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>>st;
//         for(int i=0;i<nums.size();i++){
//             set<int>hashset;
//             for(int j=i+1 ;j<nums.size();j++){
//                 int third=-(nums[i]+nums[j]);
//                 if(hashset.find(third)!=hashset.end()){
//                     vector<int>temp={nums[i],nums[j],third};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
        

//     }
// };




//brute force - tle for 3 loops
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>>st;
//         for(int i=0 ;i<nums.size();i++){
//             for(int j=i+1 ;j<nums.size();j++){
//                 for(int k=j+1 ;k<nums.size();k++){
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int>temp={nums[i],nums[j],nums[k]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }

//                  }
//              }

//         }
//         //set ko vector mei convert krdo
//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;

        
//     }
// };