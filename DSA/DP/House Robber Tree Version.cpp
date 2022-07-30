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
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        if(root==nullptr)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
            root->val;
        if(dp.find(root)!=dp.end())
            return dp[root];
        int pick=root->val;
        int not_pick=rob(root->right)+rob(root->left);;
        if(root->right!=NULL){
            pick+=rob(root->right->right)+rob(root->right->left);
        }
        if(root->left!=NULL){
            pick+=rob(root->left->right)+rob(root->left->left);
        }
        return dp[root]=max(pick,not_pick);
        
    }
};