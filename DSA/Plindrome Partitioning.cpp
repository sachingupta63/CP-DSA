class Solution {
public:
    vector<vector<string>> ans;
    bool isPlindrome(int i,int j,string s){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void dp_solve(string s,int ind,vector<string> v){
        if(ind==s.length()){
            ans.push_back(v);
            return;
        }
            
        for(int i=ind;i<s.length();i++){
            
            if(isPlindrome(ind,i,s)){
                string temp="";
                for(int j=ind;j<=i;j++){
                    temp+=s[j];
                }
                v.push_back(temp);
                dp_solve(s,i+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        dp_solve(s,0,v);
        return ans;
    }
};