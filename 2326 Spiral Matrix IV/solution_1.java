/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        
        int[][] ans = new int[m][n];
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                ans[i][j] = -1;
                
        int i = 0, j = 0, i_min = 0, i_max = m-1, j_min = 0, j_max = n - 1, dir = 0;

        while (head != null)
        {
            ans[i][j] = head.val;
            head = head.next;

            if (dir == 0) // right
            {
                if (j == j_max)
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
                if (i == i_max)
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
            else // up
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
}
