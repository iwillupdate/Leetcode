class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        int n=pizzas.size()/4;
        long long ans=0;
        for(int i=0 ; i<(n+1)/2 ;i++){
            ans = ans + pizzas[pizzas.size()-1-i];

        }
        int i=pizzas.size() - ((n+1)/2) -2;
        for(int j=0 ; j<n/2 and i>0 ; j++ , i=i-2){
            ans = ans+pizzas[i];
        }
        return ans;
        
    }
};