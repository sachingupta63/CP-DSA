class Solution {
public:
    
    int stock(vector<int>& prices,int i,int transaction,int buy,vector<vector<vector<int>>>& dp){
        if(transaction<=0)
            return 0;
        if(i==prices.size())
            return 0;
        if(dp[i][transaction][buy]!=-1)
            return dp[i][transaction][buy];
        
        if(buy==0){
            return dp[i][transaction][buy]=max(stock(prices,i+1,transaction,buy,dp),-prices[i]+stock(prices,i+1,transaction,1,dp));
        }
        
        return dp[i][transaction][buy]=max(stock(prices,i+1,transaction,buy,dp),prices[i]+stock(prices,i+1,transaction-1,0,dp));
        
        
        
    }
    int maxProfit(vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return stock(prices,0,2,0,dp);
    }
};