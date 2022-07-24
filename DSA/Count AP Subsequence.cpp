#define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,ll>> dp(n);
        long long int mod=1e9;
        long long int sum=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll dif=(ll)nums[i]-nums[j];
                if(dif>INT_MAX || i<INT_MIN)
                    continue;
                if(dp[j].find(dif)!=dp[j].end()){
                    dp[i][dif]+=(dp[j][dif]+1);       //storing number of Ap lem>=3
                    sum+=dp[j][dif];
                }else{
                    dp[i][dif]+=1;
                }
            }
        }
        
        // int sum=0;
        // for(auto x:dp){
        //     for(auto pr:x){
        //         if(pr.second>1){
        //             sum=(sum+pr.second+1)%mod;
        //         }
        //     }
        // }
        return sum;
        
    }
};