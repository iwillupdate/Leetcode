class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int l=0;
        unordered_map<char,int>char_count={{'a' ,0 } , {'b',0} , {'c',0}};

        for(int r=0;r<s.length();r++){
            char_count[s[r]]++;

             while(char_count['a'] > 0  && char_count['b'] > 0 && char_count['c'] > 0){
            cnt+=s.length()-r;
            char_count[s[l]]--;
            l++;
            }
         }
         return cnt;
       
    }
};