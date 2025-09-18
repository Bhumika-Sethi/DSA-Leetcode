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
    TreeNode* deleteTheNode(TreeNode* root, int key){
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL){
                TreeNode* newRoot = root->right;
                delete root;
                return newRoot;
            }
            else if(root->right==NULL){
                TreeNode* newRoot = root->left;
                delete root;
                return newRoot;
            }
            else{
                TreeNode* newNode = root->left;
                TreeNode* node = root->left;
                while(node->right!=NULL){
                    node = node->right;
                }
                node->right = root->right;
                delete root;
                return newNode;
            }
        }
        if(root->val>key){
            TreeNode* nodeL = deleteTheNode(root->left,key);
            root->left = nodeL;
        }
        else{
            TreeNode* nodeR = deleteTheNode(root->right,key);
            root->right = nodeR;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteTheNode(root,key);
    }
};