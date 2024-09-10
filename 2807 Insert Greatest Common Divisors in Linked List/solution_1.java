/*
  tc - O(N)
  sc - O(1)
*/

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

    private int gcd(int a, int b)
    {
        if (b == 0)
            return a;

        return gcd(b, a%b);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        
        ListNode p = head, q = head.next;
        while (q != null)
        {
            ListNode gcd = new ListNode(gcd(p.val, q.val), q);
            p.next = gcd;
            p = p.next.next;
            q = q.next;
        }

        return head;
    }
}
