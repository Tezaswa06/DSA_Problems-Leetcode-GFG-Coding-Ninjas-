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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *tail = dummy;

        while(curr!= nullptr){
            if(curr -> next != nullptr && curr -> val == curr -> next -> val){
                int temp = curr -> val;
                while(curr != nullptr && curr -> val == temp){
                    curr = curr -> next;
                }
            }
            else{
                tail -> next = curr;
                tail = curr;
                curr = curr -> next;
            }
        }
        tail -> next = nullptr;
        return dummy -> next;
    }
};