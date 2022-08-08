class Solution {
public:
    
    
    int longestIdealString(string s, int k) {
        
        vector<int> dp(30,0);
        
        for(int i=0;i<s.length();i++){
            int maxi=dp[s[i]-'a'];
            for(int j=0;j<=25;j++){
                if(abs(j-(s[i]-'a'))<=k){
                    
                    maxi=max(maxi,1+dp[j]);
                    
                }
            }
            dp[s[i]-'a']=maxi;
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};