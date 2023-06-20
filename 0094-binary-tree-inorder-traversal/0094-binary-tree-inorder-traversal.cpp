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
    
    void recTraversal(TreeNode* root, vector<int>& v){
        if(root==NULL){
            return;
        }
        
        recTraversal(root->left,v);
        v.push_back(root->val);
        recTraversal(root->right,v);
    }
    
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        recTraversal(root,inorder);
        return inorder;
    }
};