class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while (fast != NULL)
        {
            if(fast -> next != NULL)
            {
                fast = fast -> next;
            }
            fast = fast -> next;
            slow = slow -> next;
        }
      if (slow == fast)
      {
        slow = head 
          while (slow != fast)
          {
            slow = slow -> next;
            fast = fast -> next;
          }
        
      }
        return slow;
    }
};
