class Solution {
public:
    string smallestNumber(string p) {
        
        string ans="123456789";
        p.push_back('a');
        if(p.length()==1)
            return "1";
        
        for(int i=0;i<p.length();i++){
            if(p[i]=='a')
                continue;
            if(p[i]==p[i+1]){
                int k=i;
                while(i<p.length() && p[i]==p[i+1]){
                    i++;
                }
                
                if(p[i]=='D')
                    reverse(ans.begin()+k,ans.begin()+i+2);
                
                
                
            }else{
                 if(p[i]=='D')
                    swap(ans[i+1],ans[i]); 
            }
            
        }
        return ans.substr(0,p.length());
        
    }
};