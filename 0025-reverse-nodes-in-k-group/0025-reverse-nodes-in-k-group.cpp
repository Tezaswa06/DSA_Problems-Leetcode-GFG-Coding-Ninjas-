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
    int sizeOfLL(ListNode *head){
        ListNode *curr = head;
        int count = 0;
        while(curr != nullptr){
            count++;
            curr = curr -> next;
        }
        return count;
    }
    ListNode *ReverseLL(ListNode *head){
        ListNode *curr = head;
        ListNode *prevptr = nullptr;
        ListNode *ahead = head;

        while(curr != nullptr){
            ahead = curr -> next;
            curr -> next = prevptr;
            prevptr = curr;
            curr = ahead;
        }
        return prevptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        int n = sizeOfLL(head);

        ListNode *resHead = new ListNode(-1);
        ListNode *resTail = resHead;


        while(curr != nullptr){
            if(n < k){
                resTail -> next = curr;
                break;
            }
            n = n - k;
            ListNode *groupHead = new ListNode(-1);
            ListNode *groupTail = groupHead;

            for(int i = 0 ; i < k ; i++){
                groupTail -> next = curr;
                groupTail = curr;
                curr = curr -> next;
            }
            groupTail -> next = nullptr;
            groupHead = groupHead -> next;
            ReverseLL(groupHead);
            resTail -> next = groupTail;
            resTail = groupHead;
        }
        return resHead -> next;
    }
};
