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
    vector<string>paths;

    void dfs(TreeNode* root,string path){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            path += to_string(root -> val);
            paths.push_back(path);
            return;
        }
        dfs(root -> left,path + to_string(root -> val) + "->");
        dfs(root -> right,path + to_string(root -> val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return paths;
    }
};