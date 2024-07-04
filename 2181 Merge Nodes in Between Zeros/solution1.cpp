/*
  tc - O(N)
  sc - O(1)
*/

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
    ListNode* mergeNodes(ListNode* head) {
        /*
        - first iteration, make the range
            - maintain
                start (1st 0)
                end (next 0)
                currSUm to store sum of nos. in between
        - second remove the 0s
        */
        ListNode *start = head, *end = head->next;
        int currSum = 0;
        while (end)
        {
            while (end->val != 0)
            {
                currSum += end->val;
                end = end->next;
            }

            start->next->val = currSum;
            currSum = 0;
            start->next->next = end;
            start = end;
            end = end->next;
        }

        ListNode *ptr1 = head, *ptr2 = head->next;
        while (ptr2)
        {
            if (ptr2->val != 0)
            {
                ptr1 = ptr1->next;
                ptr1->val = ptr2->val;
            }

            ptr2 = ptr2->next;
        }

        ptr1->next = nullptr;
        return head->next;
    }
};
