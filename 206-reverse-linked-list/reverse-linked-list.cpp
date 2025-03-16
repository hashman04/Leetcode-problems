// OJ: https://leetcode.com/problems/reverse-linked-list/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode h;
        while (head) {
            auto p = head;
            head = head->next;
            p->next = h.next;
            h.next = p;
        }
        return h.next;
    }
};