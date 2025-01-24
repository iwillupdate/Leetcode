class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int j = -1;
        int n=a.size();
        //place the pointer j:
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                j = i;
                break;
            }
        }

        //no non-zero elements:
        if (j == -1) return ;

        //Move the pointers i and j
        //and swap accordingly:
        for (int i = j + 1; i < n; i++) {
            if (a[i] != 0) {
                swap(a[i], a[j]);
                j++;
            }
        }
    }
};


// class Solution {
// // public:
// //     void moveZeroes(vector<int>& nums) {
// //         int l=0;
// //         for(int i=0 ; i<nums.size() ; i++){
// //             if(nums[i]!=0){
// //                 swap(nums[i] , nums[l]);
// //                 l++;
// //             }
// //         }
        
// //     }
// // };
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         vector<int> temp;
//         for(int i=0 ; i<nums.size() ; i++){
//             if(nums[i]!= 0){
//                 temp.push_back(nums[i]);
//             }
//         }

//         int nz = temp.size();
//         for(int i=0 ; i<nz ; i++){
//             nums[i]=temp[i];
//         }
//         for(int i=nz ; i<nums.size() ; i++){
//             nums[i]=0;
//         }
//     }
// };