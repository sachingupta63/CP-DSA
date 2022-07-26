class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        
        
        
        //DP solution Of AP Longest
        unordered_map<int,int> dp;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
                dp[arr[i]]=max(dp[arr[i]],dp[arr[i]-dif]+1);
                maxi=max(maxi,dp[arr[i]]);
           
        }
        return maxi;
        
    }
};