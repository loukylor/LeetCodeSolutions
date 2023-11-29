# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        middle = head
        curr = head
        while curr is not None:
            # advance middle once
            middle = middle.next

            # advance current twice
            curr = curr.next
            if curr != None:
                curr = curr.next
        
        # middle will now always be the value after the middle element
        # now reverse middle, and merge the two
        last_node = None
        while middle is not None:
            temp = middle.next
            middle.next = last_node
            last_node = middle
            middle = temp
        
        # middle is now reversed
        middle = last_node

        # now loop through original and add in middle
        curr = head
        while middle is not None:
            temp = middle.next
            middle.next = curr.next
            curr.next = middle

            curr = middle.next
            middle = temp

        # make sure the last element has no next element
        curr.next = None
        
        return head
