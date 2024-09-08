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
    public ListNode[] splitListToParts(ListNode head, int k) {

        int cnt = 0;
        ListNode ptr = head;
        
        while (head != null)
        {
            cnt++;
            head = head.next; 
        }

        int[] cnts = new int[k];
        int per_cnt = cnt / k;
        int rem = cnt % k;

        for (int i=0;i<k;i++)
        {
            cnts[i] = per_cnt + (rem>0 ? 1 : 0);
            if (rem>0)
                rem--;
        }

        ListNode[] ans = new ListNode[k];

        for (int i=0;i<k;i++)
        {
            ListNode currHead = ptr;
            while (cnts[i]-->0)
            {
                if (cnts[i] == 0)
                {
                    ListNode next_ = ptr.next;
                    ptr.next = null;
                    ptr = next_;
                }
                else
                {
                    ptr = ptr.next;
                }
            }

            ans[i] = currHead;
        }
        
        return ans;
    }
}
