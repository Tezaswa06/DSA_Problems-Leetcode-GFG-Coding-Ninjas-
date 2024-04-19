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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        ListNode *curr = head;
        ListNode *ahead = head;
      

        while(curr != nullptr && curr -> next != nullptr){
            ahead = curr -> next;
            tail -> next = ahead;
            tail = ahead;
            curr -> next = ahead -> next;
            tail -> next = curr;
            tail = curr;
            curr = curr -> next;
        }
        
        return dummy -> next;
    }
};