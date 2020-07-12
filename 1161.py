# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        q = [root]
        max_level = 1
        level = 1
        max_count = -100000
        
        while len(q) > 0:
            tmp = 0
            tmp_q = []
            for i in range(len(q)):
                tmp += q[i].val
                if q[i].left:
                    tmp_q.append(q[i].left)
                if q[i].right:
                    tmp_q.append(q[i].right)
            q = list(tmp_q)
                
            if tmp > max_count:
                max_count = tmp
                max_level = level
            
            level += 1
        
        return max_level
        
