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

    //better :: selfdoen using hashmap 
    ListNode *detectCycle(ListNode *head) {
    //     unordered_map<ListNode* , int>mp;
    //     ListNode* temp = head;
    //     while(temp){
    //         if(mp.find(temp)!=mp.end()){
    //             return temp;
    //         }
    //         mp[temp]++;
    //         temp = temp->next;
    //     }
    // return nullptr;

    //optimal:tortoise and hare

    //s1 detect intersection of loop || if loop exists
    // ListNode* fast = head;
    // ListNode* slow = head;
    // while(fast!=nullptr && fast->next != nullptr){
    //     fast = fast->next->next;
    //     slow = slow->next;
    //     if(slow==fast) break;
    // }

    // if(fast == nullptr || fast->next == nullptr) return nullptr;

    // //s2 resest one of pointer and fast stay at intersection point
    // // from this move both the pointers by one step ahead till 
    // //they meet , but when they meet we can say that is the starting point of the cycle
    // //why this happen , theres a proof behind this watch striversvid
    // slow = head;
    // while(slow){
    //     if(slow == fast) return slow;
    //     slow= slow->next;
    //     fast = fast->next;
    // }
    // return nullptr;

    // can be done in single loop
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow ==fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }

    }
    return nullptr;
    }
};