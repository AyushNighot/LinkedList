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
     ListNode* reverseLL(ListNode* node) 
     {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }

    void reorderList(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* rev = reverseLL(slow);
        ListNode* curr = head;

        while(rev -> next != NULL)
        {
            ListNode* tempcurr = curr -> next;
            curr -> next = rev;


            ListNode* temprev = rev -> next ;
            rev -> next = tempcurr;

            curr = tempcurr;
            rev = temprev;
        }
    }
};

---------------------------------------------------------------______WithOut Stack Space ---------------____(_----------------------------------

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
 

    ListNode* curr;

    void solve(ListNode* head)
    {
        ///base case
        if(head == NULL)
        {
            return;
        }

        solve(head -> next);

        ListNode* temp = curr -> next;
        if(curr -> next == NULL)
        {
            return;
        }
        else if(curr == head)
        {
            head -> next = NULL;
            return;
        }

        curr -> next = head;
        head -> next = (temp == head) ? NULL : temp;

        curr = temp;

    }
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};
