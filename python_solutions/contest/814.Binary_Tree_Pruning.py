# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return None
        
        left = self.pruneTree(root.left)
        right = self.pruneTree(root.right)
        root.left = left
        root.right = right
        
        if root.left is None and root.right is None and root.val == 0:
            return None
            
        return root