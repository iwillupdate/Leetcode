class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=0;
        for(int i=0 ; i<prices.size();i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            else{
                maxi=max(maxi,prices[i]-mini);
            }
        }
        return maxi;
        
    }
};

// #include<algorithm>
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int max_profit=0;
//         int min_so_far=prices[0];
//         for(int i=0 ; i<prices.size() ; i++){
//             min_so_far = std :: min(min_so_far , prices[i]);
//             int profit = prices[i]-min_so_far;
//             max_profit = std :: max(max_profit , profit);
//         }
//         return max_profit;
        
//     }
// };