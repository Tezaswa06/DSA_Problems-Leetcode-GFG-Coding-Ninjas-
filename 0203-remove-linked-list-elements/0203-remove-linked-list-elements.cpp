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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *tail = dummy;
        ListNode *curr = head;

        while(curr != nullptr){
            if(curr -> val != val){
                tail -> next = curr;
                tail = curr;
            }
            curr = curr -> next;
        }
        tail -> next = nullptr;
        return dummy -> next;
    }
};