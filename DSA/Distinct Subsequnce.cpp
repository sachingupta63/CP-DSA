class Solution {
public:
    
    
    
    int dp_solve(string s1,string s2,int i,int j,vector<vector<int>>& dp){
        
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s1[i]==s2[j]){
            int a=-1,b=-1;
            if(i-1>0 && dp[i-1][j]!=-1)
                a=dp[i-1][j];
            if(i-1>0 && j-1>0 && dp[i-1][j-1]!=-1)
                b=dp[i-1][j-1];
            if(a==-1)
                a=dp_solve(s1,s2,i-1,j,dp);
            if(b==-1)
                b=dp_solve(s1,s2,i-1,j-1,dp);
            return dp[i][j]= a+b;
        }
        if(i-1>0 && dp[i-1][j]!=-1)
            return dp[i-1][j];
            
         return dp[i][j]=dp_solve(s1,s2,i-1,j,dp);
        
    }
    int numDistinct(string s, string t) {
        int mod=1e9+7;
         vector<vector<long long int>> dp(s.length()+1,vector<long long int>(t.length()+1));
        for(int i=0;i<=s.length();i++){
            dp[i][0]=1;
        }
        for(int j=1;j<=t.length();j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[s.length()][t.length()];
        // return dp_solve(s,t,s.length()-1,t.length()-1,dp);
        
        
    }
};