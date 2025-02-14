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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int getLength(ListNode *head) {
        int ans = 0;
        for (; head; head = head->next, ++ans);
        return ans;
    }
    TreeNode *dfs(ListNode *head, int len) {
        if (len == 0) return NULL;
        if (len == 1) return new TreeNode(head->val);
        auto p = head;
        for (int i = 0; i < len / 2; ++i) p = p->next;
        auto root = new TreeNode(p->val);
        root->left = dfs(head, len / 2);
        root->right = dfs(p->next, (len - 1) / 2);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLength(head);
        return dfs(head, len);
    }
};