class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        for(int ele:derived){
            ans = ans^ele;
            
        }
        return ans==0;
    }
};