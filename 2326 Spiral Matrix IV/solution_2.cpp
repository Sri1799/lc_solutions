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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0, i_min = 0, i_max = m-1, j_min = 0, j_max = n-1, dir = 0;

        while (head)
        {
            ans[i][j] = head->val;
            head = head->next;

            if (dir == 0) // right
            {
                if (j == j_max) // direction to turn
                {
                    i_min = ++i;
                    dir = 1;
                }
                else
                {
                    j++;
                }
            }
            else if (dir == 1) // down
            {
                if (i == i_max) // to turn left
                {
                    j_max = --j;
                    dir = 2;
                }
                else
                {
                    i++;
                }
            }
            else if (dir == 2) // left
            {
                if (j == j_min)
                {
                    i_max = --i;
                    dir = 3;
                }
                else
                {
                    j--;
                }
            }
            else if (dir == 3) // up
            {
                if (i == i_min)
                {
                    j_min = ++j;
                    dir = 0;
                }
                else
                {
                    i--;
                }
            }
        }

        return ans;
    }
};
