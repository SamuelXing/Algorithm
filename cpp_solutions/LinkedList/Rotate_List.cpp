/*
* Given a list, rotate the list to the right by k places, where k is non-negative.

* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
*
**/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0){
        	return head;
        }
        int n=1;
        ListNode* p = head;

        // get list length
        while(p->next){
        	p=p->next;
        	n++;
        }

        k = n-k%n;
        // be a cycle
        p->next = head;
        for(int i=0; i < k;i++){
        	p = p->next;
        }

        // get new list head
        head = p->next;
        p->next = NULL;
        return head;
    }
};