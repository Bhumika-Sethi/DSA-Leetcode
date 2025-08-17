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
    int maxPathSum(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }
        int leftPathSum = max(0,maxPathSum(root->left,maxi));
        int rightPathSum = max(0,maxPathSum(root->right,maxi));
        int currentPathSum = root->val +leftPathSum + rightPathSum;
        maxi = max(maxi,currentPathSum);
        return root->val + max(leftPathSum,rightPathSum);
    } 
    int maxPathSum(TreeNode* root) {
        int maxi = -10000007;
        maxPathSum(root,maxi);  
        return maxi;   
    }
};