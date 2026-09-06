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
    ListNode* rotateRight(ListNode* head, int k) {

        // edge case: empty or single node
        if (!head || !head->next) return head;

        // step 1: find length and last node
        ListNode* tail = head;
        int len = 1;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // step 2: reduce k (avoid extra rotations)
        k = k % len;

        // if no rotation needed
        if (k == 0) return head;

        // step 3: make list circular
        tail->next = head;

        // step 4: find new tail
        // new tail is (len - k)th node
        int steps = len - k;
        ListNode* temp = head;

        for (int i = 1; i < steps; i++) {
            temp = temp->next;
        }

        // step 5: break the circle
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
    }
};