class Solution {
public:
    int dp_solve(vector<int>& nums1,vector<int>& nums2,int i,int prev1,int prev2,int swp,vector<vector<int>>& dp){
        if(i==nums1.size())
            return 0;
        if(dp[i][swp]!=-1)
            return dp[i][swp];
        if(prev1<nums1[i] && prev2<nums2[i]){
            if(nums1[i]==nums2[i])
                return dp[i][swp]=dp_solve(nums1,nums2,i+1,nums1[i],nums2[i],0,dp);
            else if(prev2<nums1[i] && prev1<nums2[i]){
                int not_swap=dp_solve(nums1,nums2,i+1,nums1[i],nums2[i],0,dp);
                int swap=1+dp_solve(nums1,nums2,i+1,nums2[i],nums1[i],1,dp);
                return dp[i][swp]=min(swap,not_swap);
            }else{
                return dp[i][swp]=dp_solve(nums1,nums2,i+1,nums1[i],nums2[i],0,dp);
            }
        }
        return dp[i][swp]=1+dp_solve(nums1,nums2,i+1,nums2[i],nums1[i],1,dp);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(3,-1));
        return dp_solve(nums1,nums2,0,-1,-1,0,dp);
    }
};