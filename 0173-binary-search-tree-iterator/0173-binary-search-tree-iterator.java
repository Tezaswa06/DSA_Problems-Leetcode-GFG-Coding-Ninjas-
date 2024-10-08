/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    Stack<TreeNode>stk;
    public BSTIterator(TreeNode root) {
        stk = new Stack<>();
        inorderSucc(root);// preprocessing pushing all the elements till left first because 
    }                     // minimum element will be in the left most node
    
    public void inorderSucc(TreeNode curr){
        while(curr != null){
            stk.push(curr);
            curr = curr.left;
        }
    }
    public int next() {
        TreeNode curr = stk.pop();// current element return
        inorderSucc(curr.right);// next element setting next larger value
        return curr.val;
    }
    
    public boolean hasNext() {
        return (stk.size() > 0);
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */