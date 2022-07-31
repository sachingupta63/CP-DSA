class Solution {
public:
    string customSortString(string order, string s) {
        
        priority_queue<pair<int,char>> pq;
        
        unordered_map<char,int> mp;
        
        int priority=order.length();
        for(auto x:order){
            mp[x]=priority;
            priority--;
        }
        
        for(auto x:s){
            if(mp.find(x)==mp.end()){
                pq.push({-1,x});
            }else{
                pq.push({mp[x],x});
            }
        }
        string ans="";
        while(!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }
        return ans;
        
    }
};