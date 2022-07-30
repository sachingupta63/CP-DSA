class Solution {
public:
    int mod=1e9+7;
    unordered_map<string,int> dp;
    int numRollsToTarget(int n, int k, int target) {
        
        if(target<0)
            return 0;
        if(target==0 && n!=0)
            return 0;
        if(n==0 && target!=0)
            return 0;
        if(n==0 && target==0)
            return 1;
        string temp=to_string(n)+","+to_string(target);
        if(dp.find(temp)!=dp.end())
            return dp[temp];
        long long int ans=0;
        for(int i=1;i<=k;i++){
            if(i<=target)
                ans=(ans%mod+numRollsToTarget(n-1,k,target-i)%mod)%mod;
            else
                break;
        }
        return dp[temp]=ans;
    }
};