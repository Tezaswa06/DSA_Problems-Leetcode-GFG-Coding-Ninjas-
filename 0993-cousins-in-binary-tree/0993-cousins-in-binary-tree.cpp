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
    int xLevel = -1;
    int xParent = -1;
    int yLevel = -1;
    int yParent = -1;

    void dfs(TreeNode* root,int level,int parent,int x,int y){
        if(root == NULL){
            return;
        }
        if(root -> val == x){
            xLevel = level;
            xParent = parent;
        }
        if(root -> val == y){
            yLevel = level;
            yParent = parent;
        }
        dfs(root -> left,level + 1,root -> val,x,y);
        dfs(root -> right,level + 1,root -> val,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,0,-1,x,y);
        return (xLevel == yLevel) && (xParent != yParent);
    }
};