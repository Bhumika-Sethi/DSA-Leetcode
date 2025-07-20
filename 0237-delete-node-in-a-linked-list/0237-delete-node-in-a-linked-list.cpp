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
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        if(temp==NULL){
            return;
        }
        if(temp->next==NULL){
            temp = NULL;
            return;
        }
        while(temp->next->next!=NULL){
            temp->val = temp->next->val;
            temp = temp->next;
        }
        temp->val = temp->next->val;
        ListNode* toBeDeleted = temp->next;
        temp->next = NULL;
        delete toBeDeleted;
        return;
    }
};