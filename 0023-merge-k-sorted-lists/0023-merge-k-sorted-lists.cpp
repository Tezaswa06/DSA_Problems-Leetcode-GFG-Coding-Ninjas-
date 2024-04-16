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
    ListNode *Merge(ListNode *list1 ,ListNode *list2){
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr;

        for(ListNode *head : lists){
            res = Merge(res,head);
        }
        return res;
    }
};