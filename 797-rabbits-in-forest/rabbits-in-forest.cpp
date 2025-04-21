class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>freq;
        for(int a:answers){
            freq[a]++;
        }
        int total=0;
        for(auto&t:freq){
            if(t.first==0){
                total=total+t.second;
                continue; 
            }
            else if(t.second>t.first+1){
                int groups=(t.second+t.first)/(t.first+1);
                total=total+groups*(t.first+1);

            }
            else{
                total=total+t.first+1;
            }
        }
        return total;
        
    }
};