class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>temp(n,0);

        for(auto itr:queries){
            int s=itr[0];
            int e=itr[1];

            temp[s]+=-1;
            if(e+1<n)temp[e+1]+=1;
        }
        for(int i=1;i<n;i++) temp[i]+=temp[i-1];
        int cnt=0;
        for(int i=0;i<n;i++){
            nums[i]+=temp[i];
            if(nums[i]<=0)cnt++;
        }
        return cnt==n;
    }
};