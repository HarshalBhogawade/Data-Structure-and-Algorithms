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
    ListNode* reverse(ListNode* node,ListNode* tail){
        if(!node || !node->next) return node;
        ListNode* curr = node;
        ListNode* prev = nullptr;
        ListNode* stop = tail->next;
        while(curr!=stop){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }



    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if(head==nullptr || head->next == nullptr || left==right) return head;

        // ListNode* dummy = new ListNode (-1);
        // dummy->next = head;
        // ListNode* prev= dummy;

        // int cnt = 1;
        // while(prev && cnt<left){
        //     cnt++;
        //     prev = prev->next;
        // }
        
        // ListNode* Left =prev->next;
        // ListNode* Right = getright(head , right);
        // ListNode* front = Right;
        
        // ListNode* revhead = reverse(Left ,front);
        // prev->next = revhead;
        // Left->next = front;
        // return dummy->next;

        if(!head || !head->next || left==right) return head;

        ListNode* temp = head;
        ListNode* Left = nullptr;
        ListNode* prev = nullptr;
        int cnt = 1;
        // get left node and previous node to the leftnode
        while(temp){
            if(cnt==left){
                Left = temp;
                break;
            }
            cnt++;
            prev = temp;
            temp = temp->next;
        }

        ListNode* Right = nullptr;
        temp = head;
        cnt =1;
        while(temp){
            if(cnt==right){
                Right = temp;
                break;
            }
            cnt++;
            temp=temp->next;
        }

        ListNode* front = Right->next;
        ListNode* Revhead = reverse(Left , Right);
        if(prev){
            prev->next = Revhead;
        }else{
            head = Revhead;
        }
        Left->next = front;

        return head;
        
        
    }
};
