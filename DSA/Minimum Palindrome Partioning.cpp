class Solution {
public:
    
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    //Matrix Chain Multiplication DP
    
//     int dp_solve(string s,int i,int j,vector<vector<int>>& dp){
//         if(i>j)
//             return 0;
        
//         if(isPlindrome(s,i,j))
//             return 0;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         int ans=INT_MAX;
//         for(int k=i;k<j;k++){
            
//             int partition=1+dp_solve(s,i,k,dp)+dp_solve(s,k+1,j,dp);
//             ans=min(ans,partition);
            
//         }
//         return dp[i][j]=ans;
        
//     }
    
//partion DP
    
    // int dp_solve(string s,int i,int n,vector<int>& dp){
    //     if(i==n)
    //         return 0;
    //     if(isPalindrome(s,i,n))
    //         return 0;
    //     if(dp[i]!=-1)
    //          return dp[i];
    //     int ans=INT_MAX;
    //     for(int k=i;k<n;k++){
    //         if(isPalindrome(s,i,k)){
    //             int partition=1+dp_solve(s,k+1,n,dp);
    //             ans=min(ans,partition);
    //         }
    //     }
    //     return dp[i]=ans;
        
    //}
    int minCut(string s) {
        //vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        //vector<int> dp(s.length()+1,-1);
//         vector<int> dp(s.length()+1,0);
//         for(int i=s.length()-1;i>=0;i--){
               
//             int ans=INT_MAX;
//             for(int k=i;k<s.length();k++){
                
//                 if(isPalindrome(s,i,k)){
//                     int partition=1+dp[k+1];
//                     ans=min(ans,partition);
                
//                 }
                
//             }
//             dp[i]=ans;
//         }
        
        
//         return dp[0]-1;
        
        //All Above Three Approaches give TLE 
        //Dont Know why after 
            //memoization ,Tabulation
        
        int n = s.size();
	vector<int> dp(n + 1, 0);
	for(int i = n - 1; i >= 0; i--) {
		int result = INT_MAX;
		for(int j = i; j < n; j++)
			if(isPalindrome(s, i, j))
				result = min(result, 1 + dp[j + 1]);
		dp[i] = result;
	}
	return dp[0] - 1;
        
    }
};