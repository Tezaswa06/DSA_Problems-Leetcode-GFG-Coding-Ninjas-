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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr = head;// this pointer will iterate to find the kth index from start
        for(int i = 1 ; i < k ; i++){
            if(curr == nullptr){
                return 0;
            }
            curr = curr -> next;
        }

        ListNode *slow = head; // fast and slow these two pointers will find the kth index from last
        ListNode *fast = head;

        for(int i = 0 ; i < k ; i++){
            if(fast == nullptr){
                return 0;
            }
            fast = fast -> next;
        }

        while(fast != nullptr){
            slow = slow -> next;
            fast = fast -> next;
        }
        swap(slow -> val , curr -> val);
        return head;

    }
};