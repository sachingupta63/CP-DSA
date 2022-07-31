class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        unordered_map<char,vector<int>> mp;
        set<string> st;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        
        for(auto x:dictionary){
            int prev=-1,flag=0;
            for(auto c:x){
                if(mp.find(c)==mp.end()){
                    flag=1;
                    break;
                }
                else{
                    auto idx=upper_bound(mp[c].begin(),mp[c].end(),prev)-mp[c].begin();
                    
                    if(idx==mp[c].size()){
                        flag=1;
                        break;
                    }else{
                        prev=mp[c][idx];
                    }
                }
            }
            
            if(flag==0){
                if(st.empty())
                    st.insert(x);
                else{
                    if(x.length()>(*(--st.end())).length()){
                        st.clear();
                        st.insert(x);
                    }else if(x.length()==(*st.begin()).length()){
                        st.insert(x);
                    }
                }
            }
        }
        if(st.empty())
            return "";
        return (*st.begin());
        
    }
};