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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        ListNode *curr = head;

        for(int i = 0 ; i < left - 1 ; i++){
            tail -> next = curr;
            tail = curr;
            curr = curr -> next;
        }
        ListNode *leftNode = curr;
        ListNode *prev = nullptr;
        ListNode *ahead = curr;
        for(int i = 0 ; i < right - left + 1 ; i++){
            ahead = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = ahead;
        }
        tail -> next = prev;
        leftNode -> next = ahead;

        return dummy -> next;
    }
};