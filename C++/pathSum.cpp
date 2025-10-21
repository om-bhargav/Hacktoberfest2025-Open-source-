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
void rec(TreeNode* root,vector<int> ans,vector<vector<int>> &res,int curr){
    if(!root) return;
    if(!root->left && !root->right){
        ans.push_back(root->val);
        curr-=root->val;
        if(curr==0) res.push_back(ans);
        return;
    }
    ans.push_back(root->val);
    rec(root->left,ans,res,curr-root->val);
    rec(root->right,ans,res,curr-root->val);
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        rec(root,temp,ans,targetSum);
        return ans;
    }
};
