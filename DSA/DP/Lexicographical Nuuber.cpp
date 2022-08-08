class Solution {
public:
    vector<int> ans;
    void solve(int n,int x){
        if(x>n)
            return;
        for(int i=0;i<=9;i++){
            int y=x*10+i;
            if(y<=n && y!=0){
                ans.push_back(y);
                solve(n,y);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        solve(n,0);
        return ans;
    }
};