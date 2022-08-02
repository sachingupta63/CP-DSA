class Solution {
public:
    bool calc(vector<int>& centre,vector<int>& cord){
        int dist=(centre[0]-cord[0])*(centre[0]-cord[0])+(centre[1]-cord[1])*(centre[1]-cord[1]);
        return (centre[2]*centre[2])>=dist;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x:queries){
            int cnt=0;
            for(auto y:points){
                if(calc(x,y)){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};