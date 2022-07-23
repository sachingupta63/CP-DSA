class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int n=nums.size();
         //vector<unordered_map<int,int>> dp(n);
        
    int res = 1;    
   vector<vector<int>> dp( n+1, vector<int> ( 2001, 1 ) );
        int maxi=INT_MIN;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                // int dif=A[i]-A[j];
                // if(dp[j].find(dif)!=dp[j].end()){
                //     dp[i][dif]=1+dp[j][dif];        
                // }else{
                //     dp[i][dif]=1;
                // }
                // maxi=max(maxi,dp[i][dif]);
            int dif = nums[i] - nums[j] + 510;
            dp[i][dif] =max( dp[i][dif],dp[j][dif] +1);
            res= max( res, dp[i][dif] );    
            }
        }
        
        return res;
        
        


        
    }
};
