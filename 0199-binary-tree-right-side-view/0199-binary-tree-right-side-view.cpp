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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        map<int,int> mp;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push({root,0});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int horizontalLine = q.front().second;

            q.pop();

            mp[horizontalLine] = node->val;

            if(node->left){
                q.push({node->left,horizontalLine+1});
            }
            if(node->right){
                q.push({node->right, horizontalLine+1});
            }
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};