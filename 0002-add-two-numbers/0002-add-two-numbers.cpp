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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp  = head;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = 0;
            sum+=carry;
            sum+=l1->val;
            sum+=l2->val;
            l1 = l1->next;
            l2 = l2->next;
            int ans = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(ans);
            temp->next = newNode;
            temp = newNode;
        }

        while(l1!=NULL){
            int sum = 0;
            sum += carry;
            sum += l1->val;
            int ans = sum%10;
            carry = sum/10;
            l1 = l1->next;
            ListNode* newNode = new ListNode(ans);
            temp->next = newNode;
            temp = newNode;
        }


        while(l2!=NULL){
            int sum = 0;
            sum += carry;
            sum += l2->val;
            int ans = sum%10;
            carry = sum/10;
            l2 = l2->next;
            ListNode* newNode = new ListNode(ans);
            temp->next = newNode;
            temp = newNode;
        }
        if(carry!=0){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = newNode;
        }
        return head->next;
    }
};