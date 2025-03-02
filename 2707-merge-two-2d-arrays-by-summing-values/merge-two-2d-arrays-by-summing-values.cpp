class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1=nums1.size() , n2=nums2.size();
        int i=0 , j=0;
        vector<vector<int>>result;
        while(i<n1 || j<n2){
            if(i<n1 && (j>=n2 || nums1[i][0] < nums2[j][0] ) ){
                result.push_back(nums1[i]);
                i++;
            }

            else if(j<n2 && (i>=n1 || nums1[i][0] > nums2[j][0])){
                result.push_back(nums2[j]);
                j++;
            }

            else{
                result.push_back({nums1[i][0] , nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }

        }
        return result;
        
    }
};