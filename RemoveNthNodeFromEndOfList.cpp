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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return NULL;
        }
        ListNode* ptr = new ListNode(0);
        ptr->next = head;
        int l = 0;
        ListNode* curr = ptr;
        while(curr != NULL) {
            curr = curr->next;
            l = l+1;
        }
        if(l == 2){
            return NULL;
        }
        curr = ptr;
        ListNode* prev = ptr;

        while(l-- > n) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        return ptr->next;
    }
};