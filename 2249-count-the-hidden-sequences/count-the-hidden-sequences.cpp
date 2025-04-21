class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long a=0,mx=0,mn=0;
        for(int i=0;i<differences.size();i++){
            a=a+differences[i];
            mx=max(mx,a);
            mn=min(mn,a);
        }
        return max(0,(int)((upper-lower)-(mx-mn)+1));
        



        
    }
};