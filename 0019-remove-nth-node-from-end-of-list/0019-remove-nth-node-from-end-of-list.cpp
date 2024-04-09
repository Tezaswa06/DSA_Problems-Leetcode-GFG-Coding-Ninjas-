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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;

        int count = 0;

        while(curr != nullptr){
            curr = curr -> next;
            count++;
        }

        if(n < 0 || n > count){
            return head;
        }
        curr = head;
        ListNode *prev = nullptr;
        
        for(int i = 0 ; i < count - n ; i++){
            prev = curr;
            curr = curr -> next;
        }
        if(prev == nullptr){
            head = head -> next;
            delete curr;
            return head;
        }
        prev -> next = curr -> next;
        delete curr;
        return head;
    }
};