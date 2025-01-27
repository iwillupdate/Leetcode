class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //n^3
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        //if(nums.size() < 4)
            //return ans;
        for(int i = 0; i < int(nums.size()) - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < nums.size() - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                long long new_target = long(target) - long(nums[i]) - long(nums[j]);
                int k = j + 1, l = nums.size() - 1;
                while(k < l)
                {
                    if(k > j + 1 && nums[k] == nums[k - 1])
                    {
                        k ++;
                        continue;
                    }
                    if(l < nums.size() - 1 && nums[l] == nums[l + 1])
                    {
                        l--;
                        continue;
                    }
                    if(nums[k] + nums[l] == new_target)
                    {
                        //cout << i << " " << j << " " << k << " " << l << endl;
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    }
                    else if(nums[k] + nums[l] < new_target)
                        k++;
                    else 
                        l--;
                }
            }
        }
        return ans;
    }










        //n^4
    //     set<vector<int>> ans;
    //     long long n=nums.size();
    //     sort(nums.begin() , nums.end());
    //     long long sum;
    //     for(long long i=0 ; i<n-3 ;i++){
    //         for(long long j=i+1 ; j<n-2 ;j++){
    //             for(long long k=j+1 ; j<n-1 ;k++){
    //                 for(long long l=k+1 ; l<n ;l++){
    //                     sum=nums[i]+nums[j]+nums[k]+nums[l];
    //                     if(sum>target)      break;
    //                     else if(sum==target){
    //                         vector<int> foursum;
    //                         foursum.push_back(nums[i]);
    //                         foursum.push_back(nums[j]);
    //                         foursum.push_back(nums[k]);
    //                         foursum.push_back(nums[l]);
    //                         ans.insert(foursum);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     vector<vector<int>> res;
    //     for(auto it :ans){
    //         res.push_back(it);
             

    //     }
    //    return res;
        
    // }
};