//optimal - extended boyer moore voting algo
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0 , cnt2=0 , ele1=INT_MIN , ele2=INT_MIN;
        for(int i=0 ;i<n ;i++){
            if(cnt1==0 && ele2!=nums[i]){
                ele1=nums[i]; 
                cnt1=1;
            }
            else if(cnt2==0 && ele1!=nums[i]){
                ele2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0 , cnt2=0; // reset the counters
        for(int i=0 ; i<n ;i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }
        int mini=int(n/3)+1;
        if(cnt1>=mini) ans.push_back(ele1);
        if(cnt2>=mini) ans.push_back(ele2);
        return ans;
        
        
    }
};









// //better approach - hashmap
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans;
//         unordered_map<int,int>mpp; // element aur uska count store hoga
//         int mini=int(n/3)+1;
//         for(int i=0 ; i<n ;i++){
//             mpp[nums[i]]++; //har ele ka cnt badhate jaao
//             if(mpp[nums[i]]==mini) ans.push_back(nums[i]);
//             if(ans.size()==2) break;
//         }
//         return ans;

        
//     }
// };









// //brute force
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>ans;
//         for(int i=0 ; i<n ;i++){
//             if(ans.size()==0 || ans[0]!=nums[i]) {
//                 int cnt=0;
//                 for(int j=0 ; j<n ;j++){
//                     if(nums[j]==nums[i]) cnt++;
//                 }
//                 if(cnt>(n/3)) ans.push_back(nums[i]);
//             }
//             if(ans.size()==2) break;
//         }
//         return ans;
        
//     }
// };