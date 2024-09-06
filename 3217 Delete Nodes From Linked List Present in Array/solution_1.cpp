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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        /*
        - make into a set
        - if head is removed
            - add extra check
        - 3 pointers
            - prev, curr, next
            - while curr
        */
        if (!head)
            return nullptr;

        ListNode *prev = nullptr, *curr = head;
        unordered_set<int> st(begin(nums), end(nums));

        while (curr && st.find(curr->val) != st.end())
        {
            curr = curr->next;
        }

        if (!curr)
            return nullptr;

        head = prev = curr;

        while (curr)
        {
            curr = curr->next;
            while (curr && st.find(curr->val) != st.end())
            {
                curr = curr->next;
            }
            
            prev->next = curr;
            prev = prev->next;
        }

        return head;
    }
};
