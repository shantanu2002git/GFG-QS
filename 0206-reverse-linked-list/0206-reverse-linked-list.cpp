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
    ListNode* reverseList(ListNode* head) {
        ListNode* store, *rev=NULL;
        while(head){
            store=head->next;  // keep remaining part
            head->next=rev;  //{it just work to reverse store}
            rev=head;
            head=store;  // restore ramaing part in the head
        }
        return rev;
    }
};