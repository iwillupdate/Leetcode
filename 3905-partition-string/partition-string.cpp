class Solution {
public:

    vector<string> partitionString(string s) {
        vector<string>ans;
        map<string,bool>mpp;
        string st="";
        for(int i=0;i<s.size();i++){
            //new segment
            st+=s[i];
            //seen or not
            if(mpp[st]==true) {
                continue;
            }
            else{
                ans.push_back(st);
                mpp[st]=true;
                st="";
            }
        }
        return ans;
        
    }
};