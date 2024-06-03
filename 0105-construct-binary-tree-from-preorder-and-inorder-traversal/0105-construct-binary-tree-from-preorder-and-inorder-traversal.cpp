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
    vector<int> preorder, inorder;

    int search(int val) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* construct(int rootidx, int left, int right) {
        if (left > right) {
            return NULL;
        }
        if (left == right) {
            return new TreeNode(preorder[rootidx]);
        }

        TreeNode* root = new TreeNode(preorder[rootidx]);
        int mid = search(preorder[rootidx]);
        root->left = construct(rootidx + 1, left, mid - 1);
        root->right = construct(rootidx + 1 + (mid - left), mid + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return construct(0, 0, inorder.size() - 1);
    }
};