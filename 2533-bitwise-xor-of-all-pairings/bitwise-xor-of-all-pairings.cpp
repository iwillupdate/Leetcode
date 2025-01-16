class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int c1=nums1.size();
        int c2=nums2.size();
        int x1=0 , x2=0;

        if(c1%2 != 0){
            for(int num:nums2){
                x2^=num;
            }
        }
        if(c2%2 != 0){
            for(int num:nums1){
                x1^=num;
            }
        }
        return x1^x2;
    }
};










// class Solution {
// // public:
// //     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
// //         int ans=0;
// //         int m = nums2.size();
// //         if(m&1){
// //             for (int ele :nums1){
// //                 ans ^=ele;

// //             }

// //         }
// //         int n=nums1.size();
// //         if(n&1){
// //             for(int ele:nums2){
// //                 ans^=ele;
// //             }
// //         }
// //         return ans;
        
// //     }
// // };
// class Solution {
// public:
//     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         int ans=0;

//         //Find contribution by first array elements
//         int m=nums2.size();
//         if(m&1){
//             for(int ele: nums1)
//                 ans^=ele;
//         }

//         //Find contribution by second array elements
//         int n=nums1.size();
//         if(n&1){
//             for(int ele: nums2)
//                 ans^=ele;
//         }
//         return ans;
//     }
// };