"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root or not root.right:
            return root
        
        # Loop through next values of root
        current = root
        while current:
            # Set left and right children next values
            current.left.next = current.right
            if current.next:
                current.right.next = current.next.left
            current = current.next

        # Recurse down a layer
        self.connect(root.left)
        
        return root
