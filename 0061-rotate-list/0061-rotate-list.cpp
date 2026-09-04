class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k %= n;

        if (k == 0)
            return head;

        // Make the list circular
        tail->next = head;

        // Find new tail
        int steps = n - k;
        while (steps--)
            tail = tail->next;

        // Break the circle
        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};