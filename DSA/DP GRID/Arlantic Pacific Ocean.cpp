class Solution {
public:
    
    int trav[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    void traverse(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<bool>>& ocean){
        
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || ocean[i][j]==true || prev>heights[i][j]){
            return;
        }
        ocean[i][j]=true;
        for(auto d:trav){
            traverse(heights,i+d[0],j+d[1],heights[i][j],ocean);
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>> pac(row,vector<bool>(col,false));
        vector<vector<bool>> atl(row,vector<bool>(col,false));
        
        for(int i=0;i<row;i++){
            traverse(heights,i,0,INT_MIN,pac);
            traverse(heights,i,col-1,INT_MIN,atl);
        }
        for(int i=0;i<col;i++){
            traverse(heights,0,i,INT_MIN,pac);
            traverse(heights,row-1,i,INT_MIN,atl);
        }
        vector<vector<int>> ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};