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
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front; 
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // Simply just reverse second half of the linkedlist
        // Check if the elements are equal

        // Find length of linked List
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        int n = cnt;
        int i = 0;
        int midIndex = cnt/2;
        temp = head;

        while(temp!=NULL && i<midIndex){
            i++;
            temp = temp->next;
        }
        ListNode* newHead = reverse(temp);

        while(head!=NULL && newHead!=NULL){
            if(head->val!=newHead->val){
                return false;
            }
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};