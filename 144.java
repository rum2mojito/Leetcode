// 144. Binary Tree Preorder Traversal

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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null) return res;
        Stack<TreeNode> st = new Stack<TreeNode>();
        st.push(root);
        
        while (!st.empty()) {
            TreeNode p = st.pop();
            if (p != null) {
                res.add (p.val);
                st.push(p.right);
                st.push(p.left);
            }
        }
        return res;
    }
}
