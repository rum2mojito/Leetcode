# Runtime: 304 ms, faster than 22.47% of Python3 online submissions for Range Sum of BST.
# Memory Usage: 22.2 MB, less than 5.22% of Python3 online submissions for Range Sum of BST.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        if root == None: return 0
        
        if root.val >= L and root.val <= R:
            return root.val + self.rangeSumBST(root.left, L, R) + self.rangeSumBST(root.right, L, R)
        else:
            return self.rangeSumBST(root.left, L, R) + self.rangeSumBST(root.right, L, R)
