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
    void inOrderTraversal(TreeNode* root, vector<int>& inOrder){
        if(root==NULL){
            return;
        }
        inOrderTraversal(root->left,inOrder);
        inOrder.push_back(root->val);
        inOrderTraversal(root->right,inOrder);
    }
    bool isSorted(vector<int>& inOrder){
        if(inOrder.size()==0 || inOrder.size()==1){
            return true;
        }

        for(int i = 1; i<inOrder.size(); i++){
            if(inOrder[i-1]>=inOrder[i]){
                return false;
            }
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        inOrderTraversal(root,inOrder);
        return isSorted(inOrder);
    }
};