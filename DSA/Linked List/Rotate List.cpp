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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(k==0 || head==nullptr){
            return head;
        }
        ListNode* temp=head;
        int j=0;
        while(temp->next!=nullptr){
            j++;
            temp=temp->next;
        }
        j++;
        
        if(j<=k){
            k=(k)%j;
        }
       // cout<<k;
        temp->next=head;
        int i=0;
        temp=head;
        
        while(i<(j-k-1)){
            temp=temp->next;
            i++;
        }
        
        head=temp->next;
        
        temp->next=nullptr;
        
        
        return head;
        
    }
};