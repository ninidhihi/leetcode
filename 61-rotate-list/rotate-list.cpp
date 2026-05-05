class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Find length and last node
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Make circular
        tail->next = head;

        // Effective rotations
        k = k % n;
        int stepsToNewHead = n - k;

        // Find new tail
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        // Break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};