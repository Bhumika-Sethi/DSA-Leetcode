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
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        return 1 + max(height(root->left),height(root->right));
    }
    
    void diameter(TreeNode* root, int& maxi){
        if(root==NULL){
            return;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        int dia = lh + rh;
        maxi = max(dia,maxi);
        
        diameter(root->left,maxi);
        diameter(root->right,maxi);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        diameter(root,maxi);
        return maxi;
    }
};