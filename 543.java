// 543. Diameter of Binary Tree

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int num_l = 0, num_r = 0;
        if (root.left != null) {
            Stack<TreeNode> st = new Stack<TreeNode> ();
            st.push(root.left);
            num_l = helper (st, 1);
        }
        if (root.right != null) {
            Stack<TreeNode> st = new Stack<TreeNode> ();
            st.push(root.right);
            num_r = helper (st, 1);
        }
        return Math.max(num_l+num_r, Math.max(diameterOfBinaryTree(root.left), diameterOfBinaryTree(root.right)) );
    }
    
    private int helper (Stack<TreeNode> st, int size) {
        TreeNode p = st.peek();
        int num_l = size, num_r = size;
        if (p.left != null) {
            st.push(p.left);
            size++;
            num_l = helper (st, size);
            size--;
        }
        if (p.right != null) {
            st.push(p.right);
            size++;
            num_r = helper (st, size);
            size--;
        }
        st.pop();
        return num_r > num_l? num_r:num_l;
    }
}
