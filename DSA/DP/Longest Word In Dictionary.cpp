class Solution {
public:
    bool static cmp(string a,string b){
        if(a.length()==b.length())
            return a<b;
        return a.length()<b.length();
    }
    string longestWord(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        vector<bool> vis(words.size(),false);
        
        for(int i=0;i<words.size();i++){
            if(words[i].length()==1)
                vis[i]=true;
        }
        string ans=words[0].size()==1?words[0]:"";
        for(int i=0;i<words.size();i++){
            for(int j=0;j<=i;j++){
                 if(vis[j]==true && words[i].substr(0,words[j].length())==words[j] && (words[i].length()-words[j].length()==1)){
                     if(ans.length()<words[i].length()){
                         ans=words[i];
                     }else if(ans.length()>words[i].length()){
                         
                     }else{
                         if(ans>words[i])
                             ans=words[i];
                     }
                     vis[i]=true;
                 }
            }
        }
        return ans;
        
        
    }
};