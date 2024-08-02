# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if head is None:
            return None

        dummy = ListNode(-1, head)
        lower_node: ListNode = dummy

        # Find lower node to base off of
        curr: ListNode = head
        last = ListNode(-1, head)
        while curr is not None:
            if curr.val >= x:
                break
            elif curr.val < x:
                lower_node = curr

            last = curr
            curr = curr.next

        # Move all values less than x to before values bigger than x
        while curr is not None:
            if curr.val < x:
                last.next = curr.next

                curr_next = curr.next
                temp = lower_node.next
                lower_node.next = curr
                lower_node.next.next = temp

                curr = curr_next
                lower_node = lower_node.next
            else:
                last = curr
                curr = curr.next

        return dummy.next
