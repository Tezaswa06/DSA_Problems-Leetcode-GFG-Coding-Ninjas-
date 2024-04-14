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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ptr = head;
        ListNode *leftdummy = new ListNode(-1);
        ListNode *rightdummy = new ListNode(-1);
        ListNode *ltail = leftdummy;
        ListNode *rtail = rightdummy;

        while(ptr != nullptr){
            if(ptr -> val < x){
                ltail -> next = ptr;
                ltail = ptr;
                ptr = ptr -> next;
            }
            else{
                rtail -> next = ptr;
                rtail = ptr;
                ptr = ptr -> next;
            }
        }
        ltail -> next = rightdummy -> next;
        rtail -> next = nullptr;
        return leftdummy -> next;

    }
};