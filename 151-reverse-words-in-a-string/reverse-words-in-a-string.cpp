class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        vector<string> list;
        int start,end;
        int i=0;
        while(i<n){
            while(i<n and s[i]==' '){
                i++;
            }
            if(i>=n){
                break;
            }
            start=i;
             while(i<n and s[i] !=' '){
                i++;
            }
            end=i-1;
            string word_found = s.substr(start , end-start+1);
            list.push_back(word_found);
        }

            string ans="";
            for(int i=list.size()-1 ; i>=0 ; i--){
                ans = ans + list[i];
                //add space
                if(i != 0){
                    ans.push_back(' ');
                }

            }

        
        return ans;
        
    }
};