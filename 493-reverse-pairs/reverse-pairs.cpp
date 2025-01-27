class Solution {
public:
    int count(vector<int> &nums, int i, int mid, int j)
    {
        vector<int> temp(j - i + 1, 0);
        int ans = 0;
        int i1 = i, i2 = mid + 1, k = 0;
        while(i1 <= mid && i2 <= j)
        {
            if(long(nums[i1]) > 2 * long(nums[i2]))
            {
                ans += (mid - i1 + 1);
                i2++;
            }
            else
                i1++;
        }
        i1 = i, i2 = mid + 1;
        while(i1 <= mid || i2 <= j)
        {
            if(i2 > j || (i1 <= mid && nums[i1] < nums[i2]))
            {
                temp[k++] = nums[i1++];
            }
            else
            {
                temp[k++] = nums[i2++];
            }
        }
        
        for(k = 0; k <= (j - i); k++)
        {
            nums[i + k] = temp[k];
        }
        return ans;
    }
    int countPairs(vector<int> &nums, int i, int j)
    {
        if(i >= j)
            return 0;
        int mid = i + (j - i) / 2;
        int ans = 0;
        ans += countPairs(nums, i, mid);
        ans += countPairs(nums, mid + 1, j);
        ans += count(nums, i, mid, j);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return countPairs(nums, 0, nums.size() - 1);
    }
        
        





    //Brute force
    // int reversePairs(vector<int>& nums) {
    //     return countPairs(nums,nums.size());
        
    // }
    // private:
    // int countPairs(vector<int>&nums ,int n){
    //     int count = 0;
    //     for(int i=0 ; i<n ;i++){
    //         for(int j=i+1 ; j<n;j++){
    //             if(nums[i]>2*nums[j]){
    //                 count++;
    //             }

    //         }
    //     }
    //     return count;
    
};