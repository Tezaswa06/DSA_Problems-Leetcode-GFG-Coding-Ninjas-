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
    ListNode *Middle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode *Reverse(ListNode *head){
        ListNode *prevPtr = nullptr;
        ListNode *curr = head;
        ListNode *ahead = head;

        while(curr != nullptr){
            ahead = ahead -> next;
            curr -> next = prevPtr;
            prevPtr = curr;
            curr = ahead;
        }
        return prevPtr;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *first = head;
        ListNode *midPtr = Middle(first);
        ListNode *second = Reverse(midPtr);

        while(first != nullptr && second != nullptr){
            if(first -> val != second -> val){
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        return true;
    }
};