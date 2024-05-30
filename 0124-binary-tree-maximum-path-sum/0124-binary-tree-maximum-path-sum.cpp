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
    long diameter = LONG_MIN;
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        long leftsum = max(height(root -> left) , 0);
        long rightsum = max(height(root -> right) , 0);

        diameter = max(leftsum + rightsum + root -> val , diameter);
        return max(leftsum,rightsum) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        height(root);
        return (int)diameter;
    }
};