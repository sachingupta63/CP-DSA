/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>> >mp;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            
            int sze=q.size();
            for(int i=0;i<sze;i++){
                auto pr=q.front();
                q.pop();
                TreeNode* node=pr.first;
                int level=pr.second.second;
                int vert=pr.second.first;
                mp[vert][level].push_back(node->val);
                if(node->left!=NULL)
                    q.push({node->left,{vert-1,level+1}});
                if(node->right!=NULL)
                    q.push({node->right,{vert+1,level+1}});
                
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto x:mp){
            vector<int> v;
            for(auto y:x.second){
            
                sort(y.second.begin(),y.second.end());
                for(auto it:y.second){
                    v.push_back(it);
                }
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};