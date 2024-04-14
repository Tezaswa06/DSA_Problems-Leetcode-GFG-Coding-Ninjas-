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
    ListNode* Reverse(ListNode *head){
        ListNode *curr = head;
        ListNode *prevPtr = nullptr;
        ListNode *ahead = head;

        while(curr != nullptr){
            ahead = ahead -> next;
            curr -> next = prevPtr;
            prevPtr = curr;
            curr = ahead;
        }
        return prevPtr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        ListNode *ptr1 = Reverse(l1);
        ListNode *ptr2 = Reverse(l2);

        int carry = 0;

        while(ptr1 != nullptr || ptr2 != nullptr || carry > 0){
            int d1 = (ptr1 != nullptr) ? ptr1 -> val : 0;
            int d2 = (ptr2 != nullptr) ? ptr2 -> val : 0;

            tail -> next = new ListNode((d1 + d2 + carry) % 10);
            carry = (d1 + d2 + carry) / 10;
            if(ptr1 != nullptr){
                ptr1 = ptr1 -> next;
            }
            if(ptr2 != nullptr){
                ptr2 = ptr2 -> next;
            }
            tail = tail -> next;
        }
        return Reverse(dummy -> next);
    }
};