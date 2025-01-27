class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i = nums.size() - 2; i >= 0; i--)
            if(nums[i] < nums[i + 1])
                break;
        if(i >= 0)
        {
            int next_bigger = i + 1;
            for(int j = i + 1; j < nums.size(); j++)
                if(nums[j] > nums[i] && nums[j] < nums[next_bigger])
                    next_bigger = j;
            int temp = nums[i];
            nums[i] = nums[next_bigger];
            nums[next_bigger] = temp;
        }
        i++;
        sort(nums.begin() + i, nums.end());
    }
        
    
};