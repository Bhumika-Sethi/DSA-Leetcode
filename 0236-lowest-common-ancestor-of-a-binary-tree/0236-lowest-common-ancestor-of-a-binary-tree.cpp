/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* rlowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode* leftNode = rlowestCommonAncestor(root->left,p,q);
        TreeNode* rightNode = rlowestCommonAncestor(root->right,p,q);
        
        if(!leftNode){
            return rightNode;
        }
        else if(!rightNode){
            return leftNode;
        }
        else{
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        return rlowestCommonAncestor(root,p,q);
    }
};