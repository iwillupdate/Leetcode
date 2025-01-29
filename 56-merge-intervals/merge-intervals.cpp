class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //O(N)+O(NlogN) are the intervals sorted ?
        vector<vector<int>>ans;
        if(intervals.size()==0)      return ans;
        sort(intervals.begin(),intervals.end());
        vector<int>temp_intervals=intervals[0];
        for(auto it : intervals){
            if(it[0]<=temp_intervals[1]){
                temp_intervals[1]=max(it[1],temp_intervals[1]);
            }
            else{
                ans.push_back(temp_intervals);
                temp_intervals=it;
            }
        }
           ans.push_back(temp_intervals);
           return ans;
           
        

        
        
    }
};