class Solution {
public:
    
    bool solve(int i,int j,int k,string s1,string s2,string s3,vector<vector<int>>& dp){
        int n=s1.length();
        int m=s2.length();
        int l=s3.length();
        
        if(i==n){
            return s2.substr(j)==s3.substr(k);    
        }
        if(j==m){
            return s1.substr(i)==s3.substr(k);    
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j]){
            if(s1[i]==s3[k])
                return dp[i][j]=solve(i+1,j,k+1,s1,s2,s3,dp) || solve(i,j+1,k+1,s1,s2,s3,dp);
            else
                return dp[i][j]=false;
        }else{
            if(s1[i]==s3[k]){
                return dp[i][j]=solve(i+1,j,k+1,s1,s2,s3,dp);
            }else if(s2[j]==s3[k]){
                return dp[i][j]=solve(i,j+1,k+1,s1,s2,s3,dp);
            }else{
                return dp[i][j]=false;
            }
        }
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.length()+s2.length())!=s3.length())
            return false;
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};