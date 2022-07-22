

class Solution {
public:

int dp[500005][4];

int func(vector<int>&obstacles,int i,int flag){
    
    if(i==obstacles.size()-1){
        return 0;
    }
    
    if(obstacles[i]==flag){
        return 1e9;
    }
    
    if(dp[i][flag]!=-1){
        return dp[i][flag];
    }
    
    if(obstacles[i+1]==0 || obstacles[i+1]!=flag){
        return dp[i][flag]=func(obstacles,i+1,flag);
    }
    
    else{
        
        int path1=(flag+1)%3;
        int path2=(flag+2)%3;
        
        if(path1==0){
            path1=3;
        }
        
        if(path2==0){
            path2=3;
        }
        
    return dp[i][flag]=1+min(func(obstacles,i,path1),func(obstacles,i,path2));
        
    }
    
    
}

int minSideJumps(vector<int>& obstacles) {
    
    int n=obstacles.size();
    
    memset(dp,-1,sizeof(dp));
    
    return func(obstacles,0,2);
    
}
};