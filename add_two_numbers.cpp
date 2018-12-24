/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*ListNode dummy(-1); // list head
        int carry = 0;
        ListNode *prev = &dummy; // pointer to list head
        for (ListNode *pa = l1, *pb = l2;
             pa != nullptr || pb != nullptr;
             pa = (pa == nullptr ? nullptr : pa->next),
             pb = (pb == nullptr ? nullptr : pb->next),
             prev = prev->next) {
            const int ai = (pa == nullptr ? 0 : pa -> val);
            const int bi = (pb == nullptr ? 0 : pb -> val);
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new ListNode(value);
        }
        if (carry > 0)
            prev->next = new ListNode(carry);
        return dummy.next;
    }*/
        ListNode dummyhead(-1); // why don't initialize to zero?
        ListNode *p = l1, *q = l2, *curr = &dummyhead;
        int carry = 0;
        
        while (p != nullptr || q != nullptr) {
            int x = (p !=nullptr) ? p->val : 0; // if p is not null, set x to p->val, otherwise 0
            int y = (q !=nullptr) ? q->val : 0; // if q is not null, set y to q->val, otherwise 0
            int sum = carry + x + y; // calculate sum of the corresponding digit x, y and carry from the previous
            carry = sum / 10;        // calculate the carry-over for next summation
            
            curr->next = new ListNode(sum % 10); //  the remainder is to be the current value
            // now curr is nullptr, but curr->next has a correct value
            curr = curr->next;             // iterate curr to the next
            if (p != nullptr) p = p->next; // iterate p to the next            
            if (q != nullptr) q = q->next; // iterate q to the next
        }
        
        if (carry > 0) {
            curr->next = new ListNode(carry); // finally if the carry-over is greater than 0, the highest digit will be carry
        }
        
        return dummyhead.next;
    }
};
