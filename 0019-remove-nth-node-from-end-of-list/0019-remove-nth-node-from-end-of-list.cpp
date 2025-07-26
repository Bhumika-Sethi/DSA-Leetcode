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
        ListNode* fast = head;
        ListNode* slow = head;
        int i = 0;
        while(i!=n){
            i++;
            fast = fast->next;
        }
        if(fast==NULL){
            ListNode* deleteNode = head;
            head = head->next;
            deleteNode->next = NULL;
            delete deleteNode;
            return head;
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* toBeDeleted = slow->next;
        slow->next = slow->next->next;
        toBeDeleted->next = NULL;
        delete toBeDeleted;
        return head;
    }
};