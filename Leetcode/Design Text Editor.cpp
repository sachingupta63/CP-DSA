class TextEditor {
public:
    stack<char> left;
    stack<char> right;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(auto x:text){
            left.push(x);
        }
    }
    
    int deleteText(int k) {
        int sze=left.size();
        int count=k;
        while(left.empty()==false && k>0){
            left.pop();
            k--;
        }
        return min(count,sze);
        
    }
    
    string cursorLeft(int k) {
        int sze=left.size();
        while(left.empty()==false && k>0){
            right.push(left.top());
            left.pop();
            k--;
        }
        if(left.empty())
            return "";
        k=10;
        string temp="";
        while(left.empty()==false && k>0){
            temp+=left.top();
            left.pop();
            k--;
        }
        reverse(temp.begin(),temp.end());
        for(auto x:temp)
            left.push(x);
        
        return temp;
        
        
        
    }
    
    string cursorRight(int k) {
        int sze=left.size();
        while(right.empty()==false && k>0){
            left.push(right.top());
            right.pop();
            k--;
        }
        if(left.empty())
            return "";
        k=10;
        string temp="";
        while(left.empty()==false && k>0){
            temp+=left.top();
            left.pop();
            k--;
        }
        reverse(temp.begin(),temp.end());
        for(auto x:temp)
            left.push(x);
        
        return temp;
        
        
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */