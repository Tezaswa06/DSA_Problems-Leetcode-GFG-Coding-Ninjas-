/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.

    // preorder serializable
    string serialize(TreeNode* root) {
        if(root == NULL){ // base case when left and right child does'nt exist then add N instead of nothing
            return "N,";
        }
        string ans = to_string(root -> val) + ",";// seperating each value of tree with comma
        ans += serialize(root -> left);
        ans += serialize(root -> right);
        return ans;
    }

    // Decodes your encoded data to tree.
    int idx = 0;// this will iterate the string that is why it is kept global
    TreeNode* dfs(vector<string>& nodes){
        if(idx >= nodes.size()){
            return NULL;
        }
        if(nodes[idx] == "N"){
            idx++;
            return NULL;
        }

        int val = stoi(nodes[idx++]);
        TreeNode* root = new TreeNode(val);
        root -> left = dfs(nodes);
        root -> right = dfs(nodes);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string>nodes;//seperating each character with comma so that we can easily parse in it
        stringstream s(data);
        string node;
        while (getline(s, node, ',')) {
            nodes.push_back(node);
        }
        return dfs(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));