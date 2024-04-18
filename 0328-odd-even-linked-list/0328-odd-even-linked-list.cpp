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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next ==  nullptr){
            return head;
        }
        ListNode *list1 = new ListNode(-1);
        ListNode *tail1 = list1;
        ListNode *list2 = new ListNode(-1);
        ListNode *tail2 = list2;

        ListNode *curr = head;
        ListNode *ahead = head;

        while(curr != nullptr){
            tail1 -> next = curr;
            tail1 = curr ;
            ahead = curr -> next;
            tail2 -> next = ahead;
            tail2 = ahead;
            curr = ahead == nullptr ? nullptr : ahead -> next;
        }
        if(tail2 != nullptr){
            tail2 -> next = nullptr;
        }
        
        tail1 -> next = list2 -> next;
        return list1 -> next;
    }
};