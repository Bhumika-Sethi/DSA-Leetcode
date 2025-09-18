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
    TreeNode* searchInBST(TreeNode* root, int val){
        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        TreeNode* leftAns = searchInBST(root->left,val);
        if(leftAns){
            return leftAns;
        }
        TreeNode* rightAns = searchInBST(root->right,val);
        if(rightAns){
            return rightAns;
        }
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchInBST(root,val);
    }
};