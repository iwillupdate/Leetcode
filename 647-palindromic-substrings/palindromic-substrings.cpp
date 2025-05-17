class Solution {
public:

    bool checkPal(int i ,int j,string str){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int sum=0;
        for(int i=0 ; i<s.length();i++){
            for(int j=i ; j<s.length();j++){
                if(checkPal(i,j,s)==true){
                    sum++;
                }
            }
        }
        return sum;
        
    }
};