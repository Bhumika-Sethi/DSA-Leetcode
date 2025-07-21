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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> mp;
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode* temp = head;
        while(temp!=NULL){
            if(mp[temp]!=0){
                return true;
            }
            mp[temp]++;
            temp = temp->next;
        }
        return false;
    }
};