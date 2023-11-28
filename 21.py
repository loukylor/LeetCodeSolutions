# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        next_ = dummy

        while True:
            # If either is null, then mergining is complete
            if list1 is None:
                next_.next = list2
                break
            elif list2 is None:
                next_.next = list1
                break
            
            # If list1 val goes before list2 val, then place it into the list
            if list1.val < list2.val:
                next_.next = list1
                list1 = list1.next
            # Else do the opposite
            else:
                next_.next = list2
                list2 = list2.next
            next_ = next_.next

        return dummy.next
