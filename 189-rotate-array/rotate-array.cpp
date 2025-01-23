class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>rotate(nums.size());
        for(int i=0;i<nums.size();i++){
            rotate[(k+i)%nums.size()]=nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = rotate[i];
        }
    }
};
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k %=nums.size();
//         reverse(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.begin()+k);
//         reverse(nums.begin()+k, nums.end());
//     }
// };