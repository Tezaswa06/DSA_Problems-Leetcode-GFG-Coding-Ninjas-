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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>levels;
        if(root == NULL){
            return levels;
        }
        queue<TreeNode*>q;
        q.push(root);
        int height = 0;
        
        while(q.size() > 0){
            vector<int>level;
            int size = q.size();
    
            for(int c = 0; c < size; c++){
                root = q.front();
                q.pop();
                level.push_back(root -> val);

                if(root -> left != NULL){
                    q.push(root -> left);
                }
                if(root -> right != NULL){
                    q.push(root -> right);
                }
            }
            
            if(height % 2 == 1){
                reverse(level.begin(),level.end());
            }
            levels.push_back(level);
            height++;
        }
        return levels;
    }
};