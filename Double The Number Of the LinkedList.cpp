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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }


    ListNode* solve(ListNode* head){
        //step 1: reverse the linked list
        head = reverse(head);

        //step 2: perform the multiplication
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;

        while(head != NULL){
            //compute the product
            int sum = carry + (2*head->val);
            //find the digit
            int digit = sum % 10;
            carry = sum/10;

            ListNode* newNode = new ListNode(digit);
            if(ansHead == NULL){
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                ansTail->next = newNode;
                ansTail = newNode;
            }

            head = head->next;
        }

        //if the carry is remaining
        while(carry != 0){
            int sum = carry;
            int digit = sum % 10;
            carry = sum/10;

            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }

        //step 3: reverse the ans
        return reverse(ansHead);
    }


    ListNode* doubleIt(ListNode* head) {
        return solve(head);
    }
};
