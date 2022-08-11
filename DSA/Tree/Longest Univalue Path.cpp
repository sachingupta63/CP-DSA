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
    int ans=1;
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        int val1=solve(root->left);
        int val2=solve(root->right);
        
        if(root->left==NULL && root->right==NULL){
            
                ans=max(ans,1);
            return 1;
        }
        if(root->left==NULL && root->right->val==root->val){
            ans=max(ans,1+val1+val2);
            return 1+val1+val2;
        }
        if(root->left==NULL && root->right->val!=root->val){
             ans=max(ans,1);
            return 1;
        }
        if(root->right==NULL && root->left->val==root->val){
             ans=max(ans,1+val1+val2);
            return 1+val1+val2;
        }
        if(root->right==NULL && root->left->val!=root->val){
             ans=max(ans,1);
            return 1;
        }
        
        if(root->val==root->left->val && root->val==root->right->val){
            ans=max({ans,1+val1+val2});
            return max(1+val1,1+val2);
        }
        if(root->val!=root->left->val && root->val==root->right->val){
            ans=max(ans,1+val2);
            return 1+val2;
        }
        if(root->val==root->left->val && root->val!=root->right->val){
            ans=max(ans,1+val1);
            return 1+val1;
        }
        if(root->val!=root->left->val && root->val!=root->right->val){
            ans=max({ans,val1,val2});
            return 1;
        }
        return 1;
        
    }
    int longestUnivaluePath(TreeNode* root) {
        int k=solve(root);
        return ans-1;
    }
};