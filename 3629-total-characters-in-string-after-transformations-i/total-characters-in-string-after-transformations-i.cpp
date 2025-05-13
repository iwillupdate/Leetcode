#include <vector>
const int MOD=1e9+7;
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(int i=0;i<t;i++){
            vector<long long>nextFreq(26,0);
            for(int j=0;j<26;j++){
                if(j==25){
                    nextFreq[0]=(nextFreq[0]+freq[25])%MOD;
                    nextFreq[1]=(nextFreq[1]+freq[25])%MOD;

                }
                else{
                    nextFreq[j+1]=(nextFreq[j+1]+freq[j])%MOD;
                }
            }
            freq=nextFreq;
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+freq[i])%MOD;
        }
        return (int)ans;
    }
};