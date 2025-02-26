class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int c=0 , cc=0;
        for(int n:nums){
            c=c+n;
            cc=cc+n;
            maxi=max(maxi,c);
            mini=min(mini,cc);

            if(c<0) c=0;
            if(cc>0)    cc=0;
        }
        mini=abs(mini);
        return max(mini,maxi);
    }
};