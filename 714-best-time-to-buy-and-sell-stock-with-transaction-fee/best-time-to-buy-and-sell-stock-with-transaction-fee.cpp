class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int aheadNotBuy=0 , aheadBuy=0 , currBuy , currNotBuy;

        for(int i=n-1 ; i>=0 ; i--){
            //sell
            currNotBuy = max(prices[i]  - fee + aheadBuy , 0 + aheadNotBuy );

            //buy
            currBuy = max(-prices[i] + aheadNotBuy , 0 + aheadBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;

    }
};