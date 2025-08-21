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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        //Node, vertial line , horizontal line
        queue<pair<TreeNode*,pair<int,int>>> q;
        // vertical line, horizontal line, node->val
        map<int,map<int,multiset<int>>> mp;

        q.push({root,{0,0}});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int verticalLine = q.front().second.first;
            int horizontalLine = q.front().second.second;
            q.pop();
            mp[verticalLine][horizontalLine].insert(node->val);

            if(node->left){
                q.push({node->left,{verticalLine-1,horizontalLine+1}});
            }

            if(node->right){
                q.push({node->right,{verticalLine+1,horizontalLine+1}});
            }
        }

        for(auto it:mp){
            vector<int> level;

            for(auto p: it.second){
                level.insert(level.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};