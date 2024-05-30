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
    int dfs(TreeNode* root , long targetSum){//JIS NODE ME KHADE HAI VHA SE HUME KITNE PATH MIL RAHE HAI YE FUNCTION WO CHECK KAR RHA HAI
        if(root == NULL){
            return 0;
        }
        targetSum -= root -> val;
        int path = (targetSum == 0) ? 1 : 0;

        path += dfs(root -> left,targetSum);
        path += dfs(root -> right,targetSum);

        return path;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        return dfs(root,targetSum) + pathSum(root -> left,targetSum) + pathSum(root -> right,targetSum); // ye wala function dfs wale function ko root bhej rha hai hur baar alag
    }
};