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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int maxSum = INT_MIN;
        int maxLevel = 0;
        int currSum = 0;
        int currLevel = 0;

        while(q.size() > 0){
            currSum = 0;
            currLevel++;
            int size = q.size();

            for(int c = 0; c < size; c++){
                root = q.front();
                q.pop();
                currSum += root -> val;

                if(root -> left != NULL){
                    q.push(root -> left);
                }
                if(root -> right != NULL){
                    q.push(root -> right);
                }
            }
            if(currSum > maxSum){
                maxSum = currSum;
                maxLevel = currLevel;
            }
        }
        return maxLevel;
    }
};