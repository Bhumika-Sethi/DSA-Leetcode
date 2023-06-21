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
    
    
    void inorder(TreeNode* root1, vector<int>& v){
        if(root1==NULL){
            return;
        }
        
        inorder(root1->left,v);
        v.push_back(root1->val);
        inorder(root1->right,v);
    }
    
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* root2 = dummy;
        vector<int> v;
        inorder(root,v);
        for(auto it: v){
            TreeNode* newNode = new TreeNode(it);            
            dummy->right = newNode;
            dummy->left = NULL;
            dummy = dummy->right;
        }
        return root2->right;
    }
};