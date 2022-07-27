class Solution {
public:
    int ans=0;
    int solve(vector<vector<char>>& mat,int i,int j,vector<vector<int>>& dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=solve(mat,i,j+1,dp);
        int diag=solve(mat,i+1,j+1,dp);
        int down=solve(mat,i+1,j,dp);
        
        if(mat[i][j]=='1'){
            int maxi=1+min({right,diag,down});
            ans=max(ans,maxi);
            return dp[i][j]=maxi;
        }
        
        return dp[i][j]=0;
    }
    int maximalSquare(vector<vector<char>>& mat) {
        vector<vector<int>> dp(mat.size()+1,vector<int>(mat[0].size()+1,-1));
        int k=solve(mat,0,0,dp);
        return ans*ans;
    }
};