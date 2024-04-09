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

 // Approach 1 My Approach

    // ListNode* middleNode(ListNode* head) {
    //     ListNode *ptr = head;
    //     ListNode *twoptr = head;
    //     if(head == nullptr ){
    //         return 0;
    //     }
    //     while(twoptr != nullptr && twoptr -> next != nullptr){
    //         ptr = ptr -> next;
    //         twoptr  = twoptr -> next -> next;
    //     }
    //     return ptr;
    // }

    ListNode* twoPassAlgo(ListNode* head){
        ListNode *curr = head;
        int count = 0;

        while(curr != nullptr){
            curr = curr -> next;
            count++;
        }

        curr = head;
        for(int i = 0 ; i < count / 2 ; i++){
            curr = curr -> next;
        }
        return curr;
    }

    ListNode* middleNode(ListNode* head) {
        return twoPassAlgo(head);
    }
};