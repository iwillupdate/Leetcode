class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        int m=rectangles[0].size();

        long long cnt=0;
        unordered_map<double,long long>mpp;
        for(long long i=0;i<n;i++){
            int wi=rectangles[i][0];
            int hi=rectangles[i][1];
            mpp[(double)wi/hi]++;
        }
        for(auto it:mpp){
            if(it.second>1){
                cnt=cnt+(it.second)*(it.second-1)/2;
            }
        }
        return cnt;

        
    }
};