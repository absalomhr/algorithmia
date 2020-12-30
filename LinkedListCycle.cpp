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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        do{
            // fast pointer
            for(int i = 0; i < 2; i++){
                if(fast -> next == NULL)
                    return false;
                fast = fast -> next;
            }
            // slow pointer
            slow = slow -> next;
        } while(slow != fast);
        return true;
    }
};