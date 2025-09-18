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
    TreeNode* insertToBST(TreeNode* root, int val){
        if(root==NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(root->val>val){
            TreeNode* nodeL = insertToBST(root->left,val);
            root->left = nodeL;
        }
        else{
            TreeNode* nodeR = insertToBST(root->right,val);
            root->right = nodeR;
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertToBST(root,val);
    }
};