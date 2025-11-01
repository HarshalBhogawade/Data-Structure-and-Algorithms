#include <bits/stdc++.h>
using namespace std;

// ---------------------- Linked List Definition ----------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ---------------------- Solution Class ----------------------
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Store all elements to remove in a set for O(1) lookups
        unordered_set<int> st(nums.begin(), nums.end());

        // Skip nodes from the start that are in the set
        while (head && st.count(head->val)) {
            head = head->next;
        }

        // Traverse the rest of the list
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            if (st.count(curr->val)) {
                // delete node: skip current node
                prev->next = curr->next;
                curr = curr->next;
            } else {
                // move forward
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

// ---------------------- Helper Functions ----------------------

// Create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); i++) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ---------------------- Main Function ----------------------
int main() {
    // Input linked list
    vector<int> listVals = {1, 2, 3, 4, 5, 6};
    ListNode* head = createList(listVals);

    cout << "Original list: ";
    printList(head);

    // Numbers to remove
    vector<int> nums = {2, 5, 6};

    // Call solution
    Solution sol;
    head = sol.modifiedList(nums, head);

    // Output result
    cout << "Modified list: ";
    printList(head);

    return 0;
}
