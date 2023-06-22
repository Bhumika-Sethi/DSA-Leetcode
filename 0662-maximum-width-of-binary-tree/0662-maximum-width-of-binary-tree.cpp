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
        // node, index of that node at that particular level         
        queue<pair<TreeNode*,long>> q;
        
        q.push({root,0});
        
        long width = 0;
        
        while(!q.empty()){
//             Find the size of the queue - indicates the no of nodes in that particular level
//             And iterate for that level in one go.
            long size = q.size();
            long mini = q.front().second;
            long first,last;
            
            
            for(int i = 0; i<size; i++){
                auto it = q.front();
                q.pop();
                
                TreeNode* node = it.first;
                long indexWithoutModification = it.second;
                long newIndex = indexWithoutModification - mini;
                
                if(i==0){
                    first = newIndex;
                }
                if(i==size-1){
                    last = newIndex;
                }
                
                if(node->left){
                    q.push({node->left,2*newIndex+1});
                }
                
                if(node->right){
                    q.push({node->right,2*newIndex+2});
                }
            }
            width = max(width,last-first+1);
        }
        
        return width;
    }
};