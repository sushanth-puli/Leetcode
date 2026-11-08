
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1)
            return head;

        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; ++i)
                kth = kth->next;
            if (!kth)
                break; 
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

           
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};