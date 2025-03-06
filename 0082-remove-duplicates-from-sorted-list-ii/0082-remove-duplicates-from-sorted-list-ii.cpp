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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* nwhead = new ListNode(-1);
        ListNode* go = nwhead;

        while (head) {
            if (head->next && head->val == head->next->val) {
                // Remove Dublicate using while loop ---running
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                go->next = head->next;
            } else {
                go->next = head;
                go = go->next;
            }
            head = head->next;
        }
        return nwhead->next;
    }
};