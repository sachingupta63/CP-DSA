class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        set<string> st;
        map<int,unordered_map<string,int>> mp;
        
        for(auto x:orders){
            st.insert(x[2]);
            mp[stoi(x[1])][x[2]]++;
        }
        
        vector<vector<string>> ans;
        
        vector<string> temp;
        temp.push_back("Table");
        for(auto it=st.begin();it!=st.end();it++){
            temp.push_back(*it);
        }
        ans.push_back(temp);
        temp.clear();
        for(auto it=mp.begin();it!=mp.end();it++){
            temp.push_back(to_string(it->first));
            
            for(int i=1;i<ans[0].size();i++){
                temp.push_back(to_string(mp[it->first][ans[0][i]]));
            }
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
        
    }
};