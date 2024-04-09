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

        // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode *curr = head;

    //     int count = 0;

    //     while(curr != nullptr){
    //         curr = curr -> next;
    //         count++;
    //     }

    //     if(n < 0 || n > count){
    //         return head;
    //     }
    //     curr = head;
    //     ListNode *prev = nullptr;
        
    //     for(int i = 0 ; i < count - n ; i++){
    //         prev = curr;
    //         curr = curr -> next;
    //     }
    //     if(prev == nullptr){
    //         head = head -> next;
    //         delete curr;
    //         return head;
    //     }
    //     prev -> next = curr -> next;
    //     delete curr;
    //     return head;
    // }

    // Approach 2 single pass 

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;
        

        for(int i = 0 ; i < n ; i++){
            if(fast == nullptr){
                return 0;
            }
            fast = fast -> next;
        }
        ListNode *prev = nullptr;
        while(fast != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
        }
        if(prev == nullptr){
            head = head -> next;
            return head;
        }
        prev -> next = slow -> next;
        delete slow;
        return head;
    }
};