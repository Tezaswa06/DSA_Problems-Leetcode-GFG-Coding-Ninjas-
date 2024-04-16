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
    // approach 1 merging two linked lists
    // ListNode *Merge(ListNode *list1 ,ListNode *list2){
    //     ListNode *ptr1 = list1;
    //     ListNode *ptr2 = list2;
    //     ListNode *dummy = new ListNode(-1);
    //     ListNode *tail = dummy;

    //     while(ptr1 != nullptr && ptr2 != nullptr){
    //         if(ptr1 -> val < ptr2 -> val){
    //             tail -> next = ptr1;
    //             tail = ptr1;
    //             ptr1 = ptr1 -> next;
    //         }
    //         else{
    //             tail -> next = ptr2;
    //             tail = ptr2;
    //             ptr2 = ptr2 -> next;
    //         }
    //     }
    //     if(ptr1 != nullptr){
    //         tail -> next = ptr1;
    //     }
    //     else{
    //         tail -> next = ptr2;
    //     }
    //     return dummy -> next;
    // }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode *res = nullptr;

    //     for(ListNode *head : lists){
    //         res = Merge(res,head);
    //     }
    //     return res;
    // }


    // Approach 2  divide and conquer 
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
    ListNode *Helper(vector<ListNode *>& lists,int left , int right){
        if(left == right){
            return lists[left];
        }
        int mid = (left + right)/2;
        ListNode *l1 = Helper(lists , left , mid);
        ListNode *l2 = Helper(lists , mid + 1 ,right);
        return Merge(l1 , l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size() == 0){
            return nullptr;
        }
        return Helper(lists , 0 , lists.size()-1);
    }
};