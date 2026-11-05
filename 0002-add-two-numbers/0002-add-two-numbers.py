# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # dummy acts as the starting point of our result list
        dummy = ListNode(0)
        curr = dummy
        carry = 0

        while l1 or l2 or carry:
            # Extract values, defaulting to 0 if we've run out of nodes
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            
            # Sum includes the carry from the previous column
            total = x + y + carry
            
            # Update carry for the next iteration
            carry = total // 10
            
            # Add the digit to our result list
            curr.next = ListNode(total % 10)
            
            # Advance pointers
            curr = curr.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            
        return dummy.next
        