class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt1=0, cnt0=0, cnt2=0;
        for(auto& ele: nums){
            if(ele==0) cnt0++;
            if(ele==1) cnt1++;
            if(ele==2) cnt2++;

        }
        int i=0;
        while(cnt0!=0){
            nums[i++]=0;
            cnt0--;
        }
        while(cnt1!=0){
            nums[i++]=1;
            cnt1--;
        }
        while(cnt2!=0){
            nums[i++]=2;
            cnt2--;
        }
    }
};