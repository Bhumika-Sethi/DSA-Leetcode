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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> q;
        if(root==NULL){
            return 0;
        }
        long maxi = 0;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long min = q.front().second;
            long first,last;

            for(int i = 0; i<size; i++){
                TreeNode* node = q.front().first;
                long index = q.front().second-min;
                q.pop();
                if(i==0){
                    first = index;
                }
                if(i==size-1){
                    last = index;
                }
                if(node->left){
                    q.push({node->left,2*index+1});
                }
                if(node->right){
                    q.push({node->right,2*index+2});
                }
            }
            maxi = max(maxi,last-first+1);
        }
        return (int)maxi;
    }
};