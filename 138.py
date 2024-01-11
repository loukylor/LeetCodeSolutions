"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head == None:
            return None

        # Create a linked list with copies inline:
        # 1 -> 2 -> 3 -> 4 to 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> 4 -> 4'
        curr = head
        while curr != None:
            curr.next = Node(curr.val, curr.next, None)
            curr = curr.next.next

        # Copy the random references from the old list to the new one
        curr = head
        while curr != None:
            if curr.random == None:
                curr = curr.next.next
                continue
            
            curr.next.random = curr.random.next
            curr = curr.next.next
        
        # Extract the new list
        new_head = Node(0)
        new_curr = new_head
        curr = head
        while curr != None:
            new_curr.next = curr.next
            new_curr = new_curr.next
            curr = curr.next.next

        return new_head.next
