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
    int floor(TreeNode *root){// this function will give the just smaller value from the node which we need to delete by travelling on the left side of the root and getting the largest value from the left side

        root = root -> left;
        while(root -> right != NULL){
            root = root -> right;
        }
        return root -> val;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(key < root -> val){
            root -> left = deleteNode(root -> left,key);
        }
        if(key > root -> val){
            root -> right = deleteNode(root -> right,key);
        }
        if(key == root -> val){
            if(root -> left == NULL){
                return root -> right;
            }
            if(root -> right == NULL){
                return root -> left;
            }
            else{
                int replace = floor(root);
                root -> val = replace;
                root -> left = deleteNode(root -> left,replace);
            }
        }
        return root;
    }
};