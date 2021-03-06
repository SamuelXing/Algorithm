/*
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* 
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,

* return 1->4->3->2->5->NULL.
*/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
     if(!head){
     	return head;
     }

     ListNode  dummy(0);
     dummy.next = head;

     ListNode* p = &dummy;
     for(int i=1; i<m; i++){
     	p = p->next;
     } 

     // p is the previous node of pm
     ListNode* pm = p->next;

     for(int i = m; i<n; i++){
     	ListNode* temp = pm->next;
     	pm->next = temp->next;
     	temp->next = p->next;
     	p->next = temp;
     }
     return dummy.next;    
    }
};