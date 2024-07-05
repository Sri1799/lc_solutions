/*
  tc - O(N)
  sc - O(N)
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        /*

        */
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *next = curr->next;

        if (next == nullptr)
            return {-1, -1};
        
        int ptr = 1;
        vector<int> ans;
        while (next)
        {
            if (curr->val > prev->val
               && curr->val > next->val)
               ans.push_back(ptr);
            else if (curr->val < prev->val
            && curr->val < next->val)
                ans.push_back(ptr);
            
            ptr++;
            prev = curr;
            curr = next;
            next = next->next;
        }

        if (ans.size() < 2)
            return {-1, -1};

        int mind = INT_MAX, maxd = INT_MIN;
        for (int i=1;i<ans.size();i++)
            mind = min(mind, ans[i]-ans[i-1]);

        maxd = ans[ans.size()-1] - ans[0];

        return {mind, maxd};
    }
};
