/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){ // we found the meeting point but we need to find the starting point where the loop is starting
                break;
            }
        }
        if(fast == nullptr || fast -> next == nullptr){
            return nullptr;
        }
        ListNode *ptr = head;// this we have taken again to traverse the loop to find the starting point of the loop
        while(ptr != slow){
            slow = slow -> next;
            ptr = ptr -> next;
        }
        return slow;
    }
};