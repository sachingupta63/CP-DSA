class Solution {
public:
    //DP Solution Tabulated 
    //T.C=O(N*N)
    //S.C=O(2*N) ~ O(N)
    //Count Number longet LIS
    
    int findNumberOfLIS(vector<int>& nums) {
        
       vector<int> count(nums.size(),1);
       vector<int> len(nums.size(),1);
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && len[j]+1>len[i]){
                    len[i]=len[j]+1;
                    count[i]=count[j];
                }else if(nums[j]<=nums[i] && len[j]+1==len[i]){
                    count[i]+=count[j];
                }
            }
        }
        int mx_len=*max_element(len.begin(),len.end());
        int ans=0;
        for(int i=0;i<len.size();i++){
            if(len[i]==mx_len){
                ans+=count[i];
            }
        }
        return ans;
        
    }
};