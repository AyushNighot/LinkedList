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

//////////////////////////////////////////////////Alternate Apporoach////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int rec(ListNode* head){
        if(head == NULL) return 0; // Base case
        head->val = head->val * 2 + rec(head->next); // Calculate double of value in node
        if(head->val > 9){ // In case the double is greater than 9 i.e cointains 2 digits, it is gaurnted double won't be greater than 18 + 9
            int x = head->val % 10; // Stores right digit
            int a = head->val / 10; // Stores left digit
            head->val = x; // Value of node is assigned the right digit
            return a; // Left digit is returned as Carry
        }
        return 0; // In case of double less than 10 there is no carry
    }
    ListNode* doubleIt(ListNode* head) {
        int c = rec(head); // Recursion is called and carry is stored
        if(c){// In case of carry after recursion has ended new node is created
            ListNode* newHead = new ListNode(c,head);
            return newHead; // New head pointer is returned
        }
        return head; // Original head is returned in case of no carry
    }
};
