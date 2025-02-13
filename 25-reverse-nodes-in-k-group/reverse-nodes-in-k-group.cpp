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
        ListNode h, *tail = &h;
        while (head) {
            auto prev = tail;
            int i = 0;
            for (auto p = head; i < k && p; ++i, p = p->next);
            if (i < k) {
                tail->next = head;
                break;
            }
            for (int i = 0; i < k && head; ++i) {
                auto node = head;
                head = head->next;
                node->next = prev->next;
                prev->next = node;
            }
            while (tail->next) tail = tail->next;
        }
        return h.next;
    }
};