class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0, currDepth = 0;
        for(char& c : s){
            currDepth += (c == '(') - (c == ')');
            maxDepth = max(maxDepth, currDepth);
        }
        return maxDepth;
    }
};