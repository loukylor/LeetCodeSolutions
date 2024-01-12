# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return False

        fast = head.next
        slow = head
        while fast != None and slow != None:
            if fast == slow:
                return True
            
            if fast.next == None:
                return False
            
            if fast.next == slow:
                return True
            
            fast = fast.next.next
            slow = slow.next

        return False
