class Solution {
public:
    
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
        vector<vector<int>> mp(n,vector<int>(n,0));
        
        for(auto x:dig){
            mp[x[0]][x[1]]=1;
            
        }
        
        int ans=0;
        for(auto x:art){
            int x1=x[0];
            int y1=x[1];
            int x2=x[2];
            int y2=x[3];
            
            int flag=1;
            for(int i=x1;i<=x2;i++){
                for(int j=y1;j<=y2;j++){
                    if(mp[i][j]!=1){
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                    break;
            }
            ans+=flag;
        }
        return ans;
        
    }
};