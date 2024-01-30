Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000


Approach 1:
-------------

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }

        //Step 1: Reverse first k nodes
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *curr = head;
        int count = 0;

        while(curr != NULL && count < k) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        //step 2: Recursion will handel remaining part
        if(next != NULL) {
            head -> next = reverseKGroup(next, k);
        }

        //Step 3: Return head of the reversed linkedlist
        return prev;
    }
};


Approach 2:
------------

