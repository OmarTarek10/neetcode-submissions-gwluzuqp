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
    bool hasCycle(ListNode* head) {
        ListNode* fptr = head;
        ListNode* sptr = head;

        while(fptr && fptr->next){
            fptr = fptr->next->next;
            sptr = sptr->next;
            if(fptr == sptr){
                return true;
            }
        }

        return false;
    }
};
