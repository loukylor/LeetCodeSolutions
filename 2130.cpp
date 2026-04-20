/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // Slow and fast pointer, where the slow pointer reverses the linked list.
        // Once the faster pointer reaches the end, 
        // have the slow pointer go backwards and start another pointer going forwards
        // take the max sum of those 2 pointers

        ListNode* prevSlow = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr) {
            fast = fast->next->next;

            // Revserse the node slow is currently on
            ListNode* temp = slow->next;
            slow->next = prevSlow;

            // Advance slow pointers
            prevSlow = slow;
            slow = temp;
        }

        // Calculate the max
        int max = 0;
        while (slow != nullptr) {
            int currentTwin = slow->val + prevSlow->val;
            if (currentTwin > max) {
                max = currentTwin;
            }

            slow = slow->next;
            prevSlow = prevSlow->next;
        }

        return max;
    }
};
