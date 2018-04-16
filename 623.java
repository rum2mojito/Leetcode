// 623. Add One Row to Tree

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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (root == null) {
            return root;
        }
        if (d == 1) {
            TreeNode p = new TreeNode(v);
            p.left = root;
            return p;
        }
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        Queue<TreeNode> q2 = new LinkedList<TreeNode>();
        q.offer(root);
        TreeNode p, pl, pr;
        int k=1;
        while (q.peek() != null && k < d-1) {
            p = q.remove();
            if (p.left != null) q2.offer(p.left);
            if (p.right != null) q2.offer(p.right);
            if (q.peek() == null) {
                q = q2;
                q2 = new LinkedList<TreeNode>();
                k++;
            }
        }
        
        while (q.peek() != null) {
            p = q.remove();
            pl = p.left;
            pr = p.right;
            p.right = new TreeNode(v);
            p.left = new TreeNode(v);
            p.right.right = pr;
            p.left.left = pl;
        }
        
        return root;
    }
}
