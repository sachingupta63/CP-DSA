class TimeMap {
    unordered_map<string,vector<string>> mp;
    unordered_map<string,vector<int>> mp2;
    
public:
    TimeMap() {
        
        
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key].push_back(value);
        mp2[key].push_back(timestamp);
        
        
        
    }
    
    string get(string key, int timestamp) {
        
        auto it=lower_bound(mp2[key].begin(),mp2[key].end(),timestamp)-mp2[key].begin();
        
        if(it==mp2[key].size()){
            if(mp2[key].size()!=0)
                return mp[key][--it];
            else
                return "";
        }else if(it==0){
            if(mp2[key][it]==timestamp)
                return mp[key][it];
            else
                return "";
        }else{
            if(mp2[key][it]==timestamp)
                return mp[key][it];
            else
                return mp[key][--it];
        }
        
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */