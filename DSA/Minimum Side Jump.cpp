

// There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

// You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

// For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
// The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

// For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
// Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0



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
