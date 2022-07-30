class Solution {
public:
    bool check_subset(unordered_map<char,int>& wd1,unordered_map<char,int>& temp){
        for(auto x:wd1){
            if(temp.find(x.first)==temp.end())
                return false;
            if(temp[x.first]<x.second)
                return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<char,int> wd1;
        vector<string> real_ans;
        
        for(auto x:words2){
            unordered_map<char,int> temp;
            for(auto c:x){
                temp[c]++;
                wd1[c]=max(wd1[c],temp[c]);
            }
        }
        
        // for(auto x:wd1){
        //     cout<<x.first<<"->"<<x.second<<endl;
        // }
        for(auto x:words1){
            unordered_map<char,int> temp;
            
            for(auto c:x){
                temp[c]++;
            }
            
            
            if(check_subset(wd1,temp)){
                real_ans.push_back(x);
            }
        }
        return real_ans;
        
    }
};