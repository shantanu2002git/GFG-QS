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
    ListNode* partition(ListNode* head, int x) {
        ListNode *part1 = new ListNode(0); // Dummy head for the first partition
        ListNode *part2 = new ListNode(0); // Dummy head for the second partition
        ListNode *gop1 = part1;
        ListNode *gop2 = part2;

        while (head) {
            if (head->val < x) {
                gop1->next = head;
                gop1 = gop1->next;
            } else {
                gop2->next = head;
                gop2 = gop2->next;
            }
            head = head->next;
        }

        gop2->next = nullptr; // End the second partition
        gop1->next = part2->next; // Link the two partitions

        return part1->next; // Return the head of the first partition
    }
};
