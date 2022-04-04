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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kthNode = NULL;
        ListNode* kthNodeFromEnd = NULL;
        ListNode* iter = head;
        int len = 0, index=0;
        while(iter)
            iter = iter->next, len++;
        iter = head;
        while(iter){
            if(index == k-1)
                kthNode = iter;
            if(index == len-k)
                kthNodeFromEnd = iter;
            		if(kthNode && kthNodeFromEnd) break;
		iter = iter -> next, index++;
	    }   
	swap(kthNode -> val, kthNodeFromEnd -> val);
	return head;
    }
};