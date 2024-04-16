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
    ListNode *Merge(ListNode *list1 , ListNode *list2){
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while(ptr1 != nullptr && ptr2 != nullptr){
            if(ptr1 -> val < ptr2 -> val){
                tail -> next = ptr1;
                tail = ptr1;
                ptr1 = ptr1 -> next;
            }
            else{
                tail -> next = ptr2;
                tail = ptr2;
                ptr2 = ptr2 -> next;
            }
        }
        if(ptr1 != nullptr){
            tail -> next = ptr1;
        }
        else{
            tail -> next = ptr2;
        }
        return dummy -> next;
    }
    ListNode *Middle(ListNode *head){
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        
        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = nullptr;
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode *mid = Middle(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return Merge(left,right);
    }
};