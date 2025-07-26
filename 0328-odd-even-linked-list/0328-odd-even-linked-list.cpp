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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> odd;
        vector<int> even;
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            if(cnt%2==0){
                even.push_back(temp->val);
            }
            else{
                odd.push_back(temp->val);
            }
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int i = 0;
        int j = 0;
        int n = even.size();
        int m = odd.size();
        while(temp!=NULL && i<n){
            temp->val = even[i++];
            temp = temp->next;
        }
        while(temp!=NULL && j<m){
            temp->val = odd[j++];
            temp = temp->next;
        }
        return head;
        
    }
};