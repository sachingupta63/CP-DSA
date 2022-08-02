class Solution {
public:
    //buy=0
    //buy=1
    
    int solve(vector<int>& prices,int idx,int buy,int k,vector<vector<vector<int>>>& dp){
        if(k<=0)
            return 0;
        
        if(dp[idx][buy][k]!=-1)
            return dp[idx][buy][k];
        if(idx>=prices.size())
            return 0;
        if(buy==0){
            return dp[idx][buy][k]=max(solve(prices,idx+1,buy,k,dp),-prices[idx]+solve(prices,idx+1,1,k,dp));
        }else{
            return dp[idx][buy][k]=max(solve(prices,idx+1,buy,k,dp),prices[idx]+solve(prices,idx+1,0,k-1,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));
        return solve(prices,0,0,k,dp);
    }
};