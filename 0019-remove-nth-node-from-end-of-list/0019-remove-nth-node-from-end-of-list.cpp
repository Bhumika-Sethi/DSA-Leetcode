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
        if(head==NULL || (head->next==NULL && n==1)){
            return NULL;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        int size = cnt;
        int toIterate = size-n;
        if(size==n){
            ListNode* toBeDeleted = head;
            head = head->next;
            toBeDeleted->next = NULL;
            delete toBeDeleted;
            return head;
        }
        int i = 0;
        ListNode* temporary = head;
        while(temporary!=NULL && i<(toIterate-1)){
            i++;
            temporary = temporary->next;
        }
        if(temporary!=NULL && temporary->next!=NULL){
            temporary->next = temporary->next->next;
        }
        return head;
    }
};