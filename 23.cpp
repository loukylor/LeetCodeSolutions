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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = nullptr;
        while (!lists.empty()) {
            root = merge2Lists(root, lists.back());
            lists.pop_back();
        }

        return root;
    }

    ListNode* merge2Lists(ListNode* root1, ListNode* root2) {
        ListNode temp;
        ListNode* curr = &temp;

        while (root1 != nullptr && root2 != nullptr) {
            if (root1->val < root2->val) {
                curr->next = root1;
                root1 = root1->next;
            } else {
                curr->next = root2;
                root2 = root2->next;
            }
            curr = curr->next;
        }

        if (root1 != nullptr) {
            curr->next = root1;
        }

        else if (root2 != nullptr) {
            curr->next = root2;
        }

        return temp.next;
    }
};