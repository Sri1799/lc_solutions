/*
  tc - O(N + k)
  sc - O(N + k)
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode *> ans(k, nullptr);
        int cnt = 0;
        ListNode *newHead = head;

        while (head)
        {
            cnt++;
            head = head->next;
        }

        int p = cnt / k;
        int rem = cnt % k, idx = 0;
        vector<int> cnts(k, p);

        while (rem--)
        {
            cnts[idx++]++;
        }

        ListNode *ptr = newHead;
        idx = 0;

        while (idx < k && ptr)
        {
            ans[idx] = ptr;
            
            for (int i=0;i<cnts[idx]-1;i++)
            {
                ptr = ptr->next;
            }

            ListNode *next = ptr->next;
            ptr->next = NULL;
            ptr = next;
            idx++;
        }

        return ans;
    }
};
