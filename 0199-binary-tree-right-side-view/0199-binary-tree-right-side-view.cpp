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

// Approach 1 wehre we are first inserting right element in the queue and then left so that we can have the first element of the right view to be stored in the array first

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
        // vector<int>rightV;
        // if(root == NULL){
        //     return rightV;
        // }
        // queue<TreeNode *>q;
        // q.push(root);
   
        // while(q.size() > 0){
        //     rightV.push_back(q.front() -> val);
        //     int size = q.size();
            
        //     for(int c = 0; c < size; c++){
        //         root = q.front();
        //         q.pop();
        //         if(root -> right != NULL){
        //             q.push(root -> right);
        //         }
        //         if(root -> left != NULL){
        //             q.push(root -> left);
        //         }
        //     }
        // }
        // return rightV;
//     }
// };

// Approach 2 implementing dequeue so that we can fetch last element insereted
class Solution{
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightV;
        if (root == NULL) {
            return rightV;
        }

        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            int size = q.size();
            rightV.push_back(q.back()->val); // Access the last element in the deque

            for (int c = 0; c < size; c++) {
                TreeNode* current = q.front();
                q.pop_front();

                if (current->left != NULL) {
                    q.push_back(current->left);
                }
                if (current->right != NULL) {
                    q.push_back(current->right);
                }
            }
        }
        return rightV;
    }
};