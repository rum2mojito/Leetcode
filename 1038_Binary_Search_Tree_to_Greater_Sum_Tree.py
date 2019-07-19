# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        if root == None: return None
        
        self.helper(root, 0)
        
        return root
    
    def helper(self, root, val):
        if root == None: return None
        if root.right != None:
            right = self.helper(root.right, val)
            root.val += right.val
        else:
            root.val += val
            
        if root.left != None:
            return self.helper(root.left, root.val)
        return root
        
        
