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
    struct Pair {
        TreeNode* head;
        TreeNode* tail;
        Pair(TreeNode* head, TreeNode* tail) : head(head), tail(tail) {}
    };

    Pair dfs(TreeNode* root) {
        if (root == nullptr) {
            return Pair(nullptr, nullptr);
        }
        if (root->left == nullptr && root->right == nullptr) {
            return Pair(root, root);
        }

        if (root->left == nullptr) {
            Pair r = dfs(root->right);
            return Pair(root, r.tail);
        }

        Pair l = dfs(root->left);
        Pair r = dfs(root->right);

        root->left = nullptr;
        root->right = l.head;

        if (r.head == nullptr) {
            return Pair(root, l.tail);
        }

        l.tail->right = r.head;
        return Pair(root, r.tail);
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};
