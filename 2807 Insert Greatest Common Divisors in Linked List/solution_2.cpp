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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode *p1 = head, *p2 = head->next;

        while (p2)
        {
            ListNode *gcd = new ListNode(__gcd(p1->val, p2->val), p2);
            p1->next = gcd;
            p1 = p1->next->next;
            p2 = p2->next;
        }

        return head;
    }
};
