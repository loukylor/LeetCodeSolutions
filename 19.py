# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        n1_back = head

        curr = head
        for i in range(n):
            curr = curr.next

        if curr == None:
            return n1_back.next

        while curr.next != None:
            curr = curr.next
            n1_back = n1_back.next

        n1_back.next = n1_back.next.next

        return head
