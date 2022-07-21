


class Solution {
public:
    
    //Custom Sort
    static bool cmp(vector<int>a,vector<int>b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    
    //Recursive with Memoization
    unordered_map<string,int> mp;
    int LIS(vector<vector<int>>& pairs,int idx,pair<int,int> prev){
        string temp=to_string(idx)+","+to_string(prev.first)+","+to_string(prev.second);
        if(idx==pairs.size())
            return 0;
        
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        int ntk=LIS(pairs,idx+1,prev);
        int tk=INT_MIN;
        if(prev.second<pairs[idx][0]){
            tk=1+LIS(pairs,idx+1,{pairs[idx][0],pairs[idx][1]});
        }
        return mp[temp]=max(tk,ntk);
            
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),cmp);
        
        vector<int> ans(pairs.size(),1);
        
        
        //Iterative DP
        int mx=1;
        for(int i=1;i<pairs.size();i++){
            for(int j=0;j<pairs.size();j++){
                if(pairs[j][1]<pairs[i][0] && ans[j]+1>ans[i]){
                    ans[i]=ans[j]+1;
                    mx=max(mx,ans[i]);
                }
            }
        }
        
        return mx;
        
    }
};