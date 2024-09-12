class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Find the length of the list
        ListNode* curr = head;
        int size = 1; // size starts at 1 because we are already on the head node
        while (curr->next != nullptr) {
            curr = curr->next;
            size++;
        }

        // Connect the tail to the head to make it a circular list
        curr->next = head;

        // k might be larger than the size of the list, so take modulo
        k = k % size;

        // Find the new tail of the rotated list (size - k steps from the current head)
        int stepsToNewHead = size - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        // The new head is the node after the new tail
        ListNode* newHead = newTail->next;

        // Break the circle by setting the next of the new tail to nullptr
        newTail->next = nullptr;

        return newHead;
    }
};
