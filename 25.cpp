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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* beforeK = nullptr;
        ListNode* afterK = head;
        int afterKCount = 0;
        ListNode* root = nullptr;

        // Advance after K pointer
        for (int i = 0; i < k; i++) {
            afterK = afterK->next;
            afterKCount++;
        }

        while (afterKCount == k) {
            ListNode* start = curr;
            ListNode* beforeStart = beforeK;

            // Reverse k group
            afterKCount = 0;
            ListNode* last = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = last;
                last = curr;
                curr = temp;

                if (afterK != nullptr) {
                    afterK = afterK->next;
                    afterKCount++;
                }
            }

            // Connect bits disconnected in reversal
            beforeK = start;
            start->next = curr;
            if (beforeStart != nullptr) {
                beforeStart->next = last;
            }

            // Store root
            if (root == nullptr) {
                root = last;
            }
        }

        return root;
    }
};