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
    ListNode *middle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;//as in the following question we need to update the tail of the middle pointer from left part to be pointed at null
        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = nullptr;
        return slow;
    }
    ListNode *reverse(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *ahead = head;

        while(curr != nullptr){
            ahead = ahead -> next;
            curr -> next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    void reorderList(ListNode* head) {

        if(head == nullptr || head -> next == nullptr){
            return;
        }
        // middle element found
        ListNode *mid = middle(head);
        
        // Initialising the left and right part
        ListNode *left = head;
        ListNode *right = reverse(mid);

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while(left != nullptr || right != nullptr){
            if(left != nullptr){
                tail -> next = left;
                tail = left;
                left = left -> next;
            }
            if(right != nullptr){
                tail -> next = right;
                tail = right;
                right = right -> next;
            }
        }
        head = dummy -> next;
    }
};