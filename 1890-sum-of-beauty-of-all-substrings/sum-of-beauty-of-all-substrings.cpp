class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0 ; i<s.size() ; i++){
            vector<int> freq(26,0);
            int maxi=0;
            for(int j=i ; j<s.size() ; j++){
                freq[s[j]-'a']++;
                maxi=max(maxi,freq[s[j]-'a']);

                int mini=INT_MAX;
                for(int f:freq){
                    if(f>0){
                        mini=min(mini,f);
                    }
                }
                sum += (maxi - mini);

            }

        }
        return sum;
        
    }
};