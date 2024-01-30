Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000


Approach 1:  (Iterative)
-------------------------

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) 
        return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forword = NULL;

        while(curr != NULL) {
            forword = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forword;
        }
        return prev;
    }
};


Approach 2 (Recursive)
------------------------

class Solution {
public:
    void Reverse(ListNode* &head, ListNode* curr, ListNode* prev) {
        //base case
        if(curr == NULL) {
            head = prev;
            return ;
        }

        ListNode* forword = curr -> next;
        Reverse(head, forword, curr);
        curr -> next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        Reverse(head, curr, prev);

        return head;
    }
};
