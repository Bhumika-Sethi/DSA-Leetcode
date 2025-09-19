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
    void kthSmallestElement(TreeNode* root, int k, vector<int>& inOrder){
        if(root==NULL){
            return;
        }
        kthSmallestElement(root->left,k,inOrder);
        inOrder.push_back(root->val);
        kthSmallestElement(root->right,k,inOrder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder;

        kthSmallestElement(root,k,inOrder);
        if(k>inOrder.size()){
            return -1;
        }
        return inOrder[k-1];
    }
};